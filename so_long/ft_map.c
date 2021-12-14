/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolle <nkolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:33:07 by nkolle            #+#    #+#             */
/*   Updated: 2021/12/14 14:09:18 by nkolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_mapalloc(char **argv, t_game *game)
{
	int		fd;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error\n Could not open mapfile! \n", 1);
		exit(0);
	}
	line = get_next_line(fd);
	game->map.col = ft_strlen(line);
	game->fields.f_col = game->map.col;
	game->fields.f_row = 0;
	while (line != NULL)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		game->fields.f_row++;
		free(line);
	}
	close(fd);
	game->map.r = game->fields.f_row;
	game->map.map = NULL;
	game->map.map = (char **)malloc(game->map.r * sizeof(char *));
	if (!game->map.map)
		return ;
	game->map.map[game->map.r] = NULL;
	ft_fill_map(argv, game, fd);
}

void	ft_fill_map(char **argv, t_game *game, int fd)
{
	char	*line;
	int		x;
	int		y;

	x = 0;
	y = 0;
	fd = open(argv[1], O_RDONLY);
	line = get_next_line(fd);
	printf(" first %c \n", line[x]);
	while (y < game->fields.f_row)
	{
		while (line[x] != '\0')
		{
			PRINT_HERE();
			game->map.map[y][x] = line[x];
			x++;
			if (line[x] == '\0' && y < game->fields.f_row)
			{
				x = 0;
				y++;
			}
			free(line);
			line = get_next_line(fd);
		}
	}
	ft_check_validmap_walls(game);
}

void	ft_check_validmap_walls(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	printf("here 3 \n");
	while (1)
	{
		if (x < game->fields.f_col && game->map.map[y][x] == '1')
			x++;
		if (y < game->fields.f_row && game->map.map[y][x] == '1')
			y++;
			printf("x = %d \n y = %d\n", x, y);
		if (x > 0 && game->map.map[y][x] == '1')
			x--;
			printf("x1 = %d \n y2 = %d\n", x, y);
		if (y > 0 && game->map.map[y][x] == '1')
			y--;
		else
		{
			printf("x2 = %d \n y2 = %d\n", x, y);
			ft_putstr_fd("Error\n Map is invalid! \n", 1);
			exit(0);
		}
		printf("das ist x %d \n, das ist y %d", x, y);
		break ;
	}
	printf("here4 \n");
	ft_check_validmap_content(game);
}

void	ft_check_validmap_content(t_game *game)
{
	int		x;
	int		y;
	char	*str;

	str = NULL;
	str = "'1', '0', 'E', 'C', 'P'";
	game->map.r = 0;
	game->map.col = 0;
	x = game->map.col;
	y = game->map.r;
	while (ft_strchr_so_long(str, game->map.map[y][x]) == 1)
	{
		if (x < game->fields.f_col)
			x++;
		if (x == game->fields.f_col)
			y++;
		if (y == game->fields.f_row && x == game->fields.f_col)
			break ;
	}
	if (ft_strchr_so_long(str, game->map.map[y][x]) == 0
		|| ft_validmap_content_count(game) == 1)
	{
		ft_putstr_fd("Error\n Map has wrong  or missing content! \n", 0);
		exit(0);
	}
}

int	ft_validmap_content_count(t_game *game)
{
	int	x;
	int	y;

	ft_reset(game);
	x = game->map.col;
	y = game->map.r;
	while (y != game->fields.f_row && x != game->fields.f_col)
	{
		while (x < game->fields.f_col)
		{
			if (game->map.map[y][x] == 'C')
				game->fields.c_count++;
			if (game->map.map[y][x] == 'E')
				game->fields.e_count++;
			if (game->map.map[y][x] == 'P')
				game->fields.p_count++;
			x++;
		}
		y++;
	}
	if ((game->fields.c_count || game->fields.e_count) < 1
		|| game->fields.p_count != 1)
		return (1);
	return (0);
}

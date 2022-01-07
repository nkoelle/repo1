/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_alloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolle <nkolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:33:07 by nkolle            #+#    #+#             */
/*   Updated: 2022/01/07 17:53:39 by nkolle           ###   ########.fr       */
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
	game->fields.f_row = 0;							// 1 oder 0?
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		game->fields.f_row++;
	}
	close(fd);
	game->map.r = game->fields.f_row;
	game->map.map = NULL;
	game->map.map = (char **)ft_calloc(game->map.col, sizeof(char *));
	if (!game->map.map)
		return ;
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
	while (line)
	{
		game->map.map[y] = line;
		y++;
		line = get_next_line(fd);
	}
	close(fd);
	ft_check_validmap_walls(game);
}

// void	ft_checkmap(t_game *game)
// {
// 	int	x;
// 	int	y;
	
// 	for(y = 0; y < game->fields.f_row; y++)
// 	{
// 		for(x = 0; x < game->fields.f_col; x++)
// 		{
// 			printf("%c ", game->map.map[y][x]);
// 		}
// 	printf("\n"); // new line
// 	}
// } 
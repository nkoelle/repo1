/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolle <nkolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 14:50:05 by nkolle            #+#    #+#             */
/*   Updated: 2022/01/17 15:45:46 by nkolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_validmap_walls(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->fields.f_row)
	{
		x = 0;
		while (x < game->fields.f_col)
		{
			if (y == 0 && game->map.map[y][x] != '1')
				return (-1);
			if ((y == game->fields.f_row - 1) && game->map.map[y][x] != '1')
				return (-1);
			if (x == 0 && game->map.map[y][x] != '1')
				return (-1);
			if ((x == game->fields.f_col - 1) && game->map.map[y][x] != '1')
				return (-1);
			x++;
		}
		y++;
	}
	ft_check_validmap_content(game);
	ft_validmap_content_count(game);
	return (0);
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
	if (ft_strchr_so_long(str, game->map.map[y][x]) == 1)
	{
		if (x < game->fields.f_col)
			x++;
		if (x == game->fields.f_col)
			y++;
		if (y == game->fields.f_row && x == game->fields.f_col)
			return ;
	}
	else if (ft_strchr_so_long(str, game->map.map[y][x]) == 0)
	{
		ft_putstr_fd("Error\n Map has wrong or missing content! \n", 0);
		exit(0);
	}
}

void	ft_validmap_content_count(t_game *game)
{
	int	x;
	int	y;

	ft_reset(game);
	y = 0;
	while (y < game->fields.f_row)
	{
		x = 0;
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
	if (game->fields.c_count < 1 || game->fields.e_count < 1
		|| game->fields.p_count != 1)
		ft_exit();
}

void	ft_check_rowandcol(char **argv, t_game *game)
{
	char	*row;
	int		fd;

	fd = open(argv[1], O_RDONLY);
	row = get_next_line(fd);
	while (row != NULL)
	{
		if ((int)ft_strlen(row) != game->fields.f_col)
			ft_exit();
		if ((int)ft_strlen(row) == game->fields.f_col)
		{
			free(row);
			row = get_next_line(fd);
		}
	}
	close(fd);
}

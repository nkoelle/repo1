/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolle <nkolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 14:50:05 by nkolle            #+#    #+#             */
/*   Updated: 2022/01/07 18:34:33 by nkolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_validmap_walls(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (game->map.map[y][x] == '1')
	{
		if (x < game->fields.f_col)
			x++;
		if (x == game->fields.f_col && y < game->fields.f_row)
			y++;
		if (y == game->fields.f_row)
			x--;
		if (x == game->fields.f_col)
			y--;
			printf("col = %d ", game->fields.f_col);
			printf("row = %d ", game->fields.f_row);
			printf("x = %d \n y = %d\n", x, y);
	}
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

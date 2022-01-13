/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolle <nkolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 15:31:37 by nkolle            #+#    #+#             */
/*   Updated: 2022/01/13 17:42:28 by nkolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_find_playercoord(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->fields.f_row)
	{
		x = 0;
		while (x < game->fields.f_col)
		{
			if (game->map.map[y][x] == 'P')
			{
				game->player.p_col = x;
				game->player.p_row = y;
				break;
			}
			x++;
		}
		y++;
	}
}
void	ft_start_game(t_game *game)
{
	ft_reset_2(game);
	ft_find_playercoord(game);
}
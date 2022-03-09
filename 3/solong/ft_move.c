/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolle <nkolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 16:19:13 by nkolle            #+#    #+#             */
/*   Updated: 2022/01/17 15:34:08 by nkolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_exitgame2(void)
{
	printf("Winner, Winner, Chicken Dinner!\n");
	exit(0);
}

void	ft_movement(t_game *game, int j, int i)
{
	int	y;
	int	x;

	x = game->player.p_col;
	y = game->player.p_row;
	if (game->map.map[y + j][x + i] == '0'
		|| game->map.map[y + j][x + i] == 'C')
	{
		game->player.count_moves++;
		game->player.p_row = y + j;
		game->player.p_col = x + i;
		if (game->map.map[y + j][x + i] == 'C')
		{
			game->fields.c_count--;
			game->map.map[y + j][x + i] = '0';
		}
		game->map.map[y][x] = '0';
		game->map.map[y + j][x + i] = 'P';
		ft_create_surface(game);
		printf("Number of Moves %d \n", game->player.count_moves);
	}
	else if (game->map.map[y + j][x + i] == 'E' && game->fields.c_count == 0)
		ft_exitgame2();
}

int	ft_move(int key, t_game *game)
{
	if (key == KEY_W)
		ft_movement(game, -1, 0);
	if (key == KEY_A)
		ft_movement(game, 0, -1);
	if (key == KEY_S)
		ft_movement(game, 1, 0);
	if (key == KEY_D)
		ft_movement(game, 0, 1);
	if (key == KEY_ESC)
		ft_exitgame();
	ft_create_surface(game);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolle <nkolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 16:19:13 by nkolle            #+#    #+#             */
/*   Updated: 2022/01/13 17:53:24 by nkolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_key_w(t_game *game)
{
	int y;
	int x;

	x = game->player.p_col;
	y = game->player.p_row;
	if (game->map.map[y - 1][x] == '0' || game->map.map[y - 1][x] == 'C')
	{
		game->player.count_moves++;
		game->player.p_row = y - 1;
		if (game->map.map[y - 1][x] == 'C')
		{
			game->fields.c_count--;
			game->map.map[y - 1][x] = '0';
		}
		game->map.map[y][x] = '0';
		game->map.map[y - 1][x] = 'P';
		ft_create_surface(game);
		printf("Number of Moves %d \n", game->player.count_moves);
	}
	else if (game->map.map[y - 1][x] == 'E' && game->fields.c_count == 0)
	{
		printf(" c = %d \n", game->fields.c_count);
		printf("Winner, Winner, Chicken Dinner!\n");
		ft_exitgame();
	}
}

void	ft_key_a(t_game *game)
{
	int y;
	int x;

	x = game->player.p_col;
	y = game->player.p_row;
	if (game->map.map[y][x - 1] == '0' || game->map.map[y][x - 1] == 'C')
	{
		game->player.count_moves++;
		game->player.p_col = x - 1;
		if (game->map.map[y][x - 1] == 'C')
		{
			game->fields.c_count--;
			game->map.map[y][x - 1] = '0';
		}
		game->map.map[y][x] = '0';
		game->map.map[y][x - 1] = 'P';
		ft_create_surface(game);
		printf("Number of Moves %d \n", game->player.count_moves);
	}
	else if (game->map.map[y][x - 1] == 'E' && game->fields.c_count == 0)
	{
		printf("Winner, Winner, Chicken Dinner!\n");
		ft_exitgame();
	}
}

void	ft_key_s(t_game *game)
{
	int y;
	int x;

	x = game->player.p_col;
	y = game->player.p_row;
	if (game->map.map[y + 1][x] == '0' || game->map.map[y + 1][x] == 'C')
	{
		game->player.count_moves++;
		game->player.p_row = y + 1;
		if (game->map.map[y + 1][x] == 'C')
		{
			game->fields.c_count--;
			game->map.map[y + 1][x] = '0';
		}
		game->map.map[y][x] = '0';
		game->map.map[y + 1][x] = 'P';
		ft_create_surface(game);
		printf("Number of Moves %d \n", game->player.count_moves);
	}
	else if (game->map.map[y + 1][x] == 'E' && game->fields.c_count == 0)
	{
		printf("Winner, Winner, Chicken Dinner!\n");
		ft_exitgame();
	}
}

void	ft_key_d(t_game *game)
{
	int y;
	int x;

	x = game->player.p_col;
	y = game->player.p_row;
	if (game->map.map[y][x + 1] == '0' || game->map.map[y][x + 1] == 'C')
	{
		game->player.count_moves++;
		game->player.p_col = x + 1;
		if (game->map.map[y][x + 1] == 'C')
		{
			game->fields.c_count--;
			game->map.map[y][x + 1] = '0';
		}
		game->map.map[y][x] = '0';
		game->map.map[y][x + 1] = 'P';
		ft_create_surface(game);
		printf("Number of Moves %d \n", game->player.count_moves);
	}
	else if (game->map.map[y][x + 1] == 'E' && game->fields.c_count == 0)
	{
		printf("Winner, Winner, Chicken Dinner!\n");
		ft_exitgame();
	}
	printf("t\n");
}

int		ft_move(int key, t_game *game)
{
	if (key == KEY_W)
		ft_key_w(game);
	if (key == KEY_A)
		ft_key_a(game);
	if (key == KEY_S)
		ft_key_s(game);
	if (key == KEY_D)
		ft_key_d(game);
	if (key == KEY_ESC)
		ft_exitgame();
	ft_create_surface(game);
	return (0);
}
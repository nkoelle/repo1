/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_map_surface.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolle <nkolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 17:29:30 by nkolle            #+#    #+#             */
/*   Updated: 2022/01/13 15:17:29 by nkolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_create_surface(t_game *game)
{
	int	x;
	int	y;

	mlx_clear_window(game->window.mlx, game->window.mlx_win);
	y = 0;
	while (y < game->fields.f_row)
	{
		x = 0;
		while (x < game->fields.f_col)
		{
			if (game->map.map[y][x] != '1')
				mlx_put_image_to_window(game->window.mlx,
					game->window.mlx_win, game->img[0]->img,
					game->window.img_size * x, game->window.img_size * y);
			mlx_put_image_to_window(game->window.mlx, game->window.mlx_win,
				ft_which_img(game, x, y), game->window.img_size * x,
				game->window.img_size * y);
			x++;
		}
		y++;
	}
}

void	*ft_which_img(t_game *game, int x, int y)
{
	if (game->map.map[y][x] == 'P')
		return (game->img[4]->img);
	if (game->map.map[y][x] == 'E')
		return (game->img[3]->img);
	if (game->map.map[y][x] == 'C')
		return (game->img[2]->img);
	if (game->map.map[y][x] == '1')
		return (game->img[1]->img);
	if (game->map.map[y][x] == '0')
		return (game->img[0]->img);
	return (NULL);
}

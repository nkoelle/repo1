/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_mapsurface.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolle <nkolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 17:29:30 by nkolle            #+#    #+#             */
/*   Updated: 2021/12/07 13:35:52 by nkolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_build_map(t_game *game)
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
					game->window.mlx, game->img[0]->img,
					game->window.img_size * x, game->window.img_size * y);
			mlx_put_image_to_window(game->window.mlx, game->window.mlx_win,
				ft_which_img(game, x, y), game->window.img_size * x,
				game->window.img_size * y);
			x++;
		}
		y++;
	}
}

void	ft_alloc_images(t_game *game)
{
	game->img[0] = ft_calloc(1, sizeof(t_img));
	game->img[0]->img = mlx_xpm_file_to_image(game->window.mlx,
			IMG_PATH, &(game->img[0]->width),
			&(game->img[0]->height));
	game->img[1] = ft_calloc(1, sizeof(t_img));
	game->img[1]->img = mlx_xpm_file_to_image(game->window.mlx, IMG_WALL,
			&(game->img[1]->width), &(game->img[1]->height));
	game->img[2] = ft_calloc(1, sizeof(t_img));
	game->img[2]->img = mlx_xpm_file_to_image(game->window.mlx,
			IMG_COLLECTIBLE, &(game->img[2]->width),
			&(game->img[2]->height));
	game->img[3] = ft_calloc(1, sizeof(t_img));
	game->img[3]->img = mlx_xpm_file_to_image(game->window.mlx, IMG_EXIT,
			&(game->img[3]->width), &(game->img[3]->height));
	game->img[4] = ft_calloc(1, sizeof(t_img));
	game->img[4]->img = mlx_xpm_file_to_image(game->window.mlx, IMG_PLAYER,
			&(game->img[4]->width), &(game->img[4]->height));
}

char	*ft_which_img(t_game *game, int x, int y)
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

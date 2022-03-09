/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolle <nkolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 17:12:52 by nkolle            #+#    #+#             */
/*   Updated: 2022/01/17 15:25:47 by nkolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_protect(char *fd1)
{
	int	len;

	len = ft_strlen(fd1);
	if (fd1 == 0)
		return (0);
	if (len < 5)
		return (0);
	if (ft_strcmp(fd1 + len - 4, ".ber") != 0)
		return (-1);
	return (0);
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

int	main(int argc, char **argv)
{	
	t_game	game;

	if (ft_protect(argv[1]) == -1 || argc != 2)
	{
		ft_putstr_fd("Error\nWrong mapsize\n", 1);
		exit(0);
	}
	ft_memset(&game, 0, sizeof(t_game));
	ft_mapalloc(argv, &game);
	game.window.mlx = mlx_init();
	game.window.mlx_win = mlx_new_window(game.window.mlx,
			(game.fields.f_col * 32), (game.fields.f_row * 32), "so_long");
	ft_alloc_images(&game);
	ft_create_surface(&game);
	ft_start_game(&game);
	mlx_hook(game.window.mlx_win, 2, (1L << 0), ft_move, &game);
	mlx_hook(game.window.mlx_win, 17, (1L << 17), ft_exitgame, &game);
	mlx_loop(game.window.mlx);
	return (0);
}

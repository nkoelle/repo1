/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolle <nkolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 17:12:52 by nkolle            #+#    #+#             */
/*   Updated: 2022/01/05 15:59:46 by nkolle           ###   ########.fr       */
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

int	ft_quit(void)
{
	exit(0);
	return (0);
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
	printf("here \n");
	game.window.mlx = mlx_init();
	game.window.mlx_win = mlx_new_window(game.window.mlx,
			(game.window.width * 100), (game.window.height * 100), "./so_long");
	printf("here3 \n");
	//ft_start_game(&game);
	mlx_loop(game.window.mlx);
	return (0);
}

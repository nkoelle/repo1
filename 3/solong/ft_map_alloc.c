/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_alloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolle <nkolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:33:07 by nkolle            #+#    #+#             */
/*   Updated: 2022/01/14 17:37:03 by nkolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_mapalloc(char **argv, t_game *game)
{
	int		fd;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_exit();
	line = get_next_line(fd);
	game->map.col = ft_strlen(line);
	game->fields.f_col = game->map.col;
	game->fields.f_row = 0;
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
	if (ft_check_validmap_walls(game) == -1)
		ft_exit();
	ft_check_rowandcol(argv, game);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolle <nkolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:02:56 by nkolle            #+#    #+#             */
/*   Updated: 2021/12/10 13:26:19 by nkolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strchr_so_long(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	while (*str != (char)c)
	{
		if ((char)c == '\0' && *str == '\0')
			return (0);
		if (*str == '\0' && (char)c != '\0')
			return (0);
		str++;
	}
	return (1);
}

void	ft_reset(t_game *game)
{
	game->map.r = 0;
	game->map.col = 0;
	game->fields.c_count = 0;
	game->fields.p_count = 0;
	game->fields.e_count = 0;
	game->window.img_size = 32;
	game->window.width = game->fields.f_col;
	game->window.height = game->map.r;
}

void	ft_exit(void)
{
	ft_putstr_fd("Error\n Map is invalid! \n", 1);
	exit(0);
}

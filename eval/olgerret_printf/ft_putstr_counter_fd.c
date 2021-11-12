/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_counter_fd.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olgerret <olgerret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 07:39:21 by olgerret          #+#    #+#             */
/*   Updated: 2021/07/24 07:39:30 by olgerret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr_counter_fd(char *s, int fd, int *counter)
{
	int	i;

	i = 0;
	if (s == 0)
		return ;
	while (s[i] != '\0')
	{
		ft_putchar_counter_fd(s[i], fd, counter);
		i++;
	}
}

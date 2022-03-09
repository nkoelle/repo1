/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolle <nkolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 18:24:40 by nkolle            #+#    #+#             */
/*   Updated: 2021/09/15 17:36:31 by nkolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *s, int *counter)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		write(1, "(null)", 6);
		*counter += 6;
		return ;
	}
	while (s[i] != '\0')
	{
		ft_putchar(s[i], counter);
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned_fd.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olgerret <olgerret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 07:39:16 by olgerret          #+#    #+#             */
/*   Updated: 2021/07/24 07:39:33 by olgerret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_unsigned_fd(unsigned int n, int fd, int *counter)
{
	if (n >= 0 && n <= 9)
	{
		n += '0';
		ft_putchar_counter_fd(n, fd, counter);
	}
	else
	{
		ft_putnbr_unsigned_fd(n / 10, fd, counter);
		ft_putnbr_unsigned_fd(n % 10, fd, counter);
	}
}

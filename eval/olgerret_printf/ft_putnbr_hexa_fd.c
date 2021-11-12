/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hexa_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olgerret <olgerret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 07:39:10 by olgerret          #+#    #+#             */
/*   Updated: 2021/07/24 07:39:34 by olgerret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ten_to_sixteen_up(unsigned long n, int fd, int *counter)
{
	if (n == 10)
		ft_putchar_counter_fd('A', fd, counter);
	else if (n == 11)
		ft_putchar_counter_fd('B', fd, counter);
	else if (n == 12)
		ft_putchar_counter_fd('C', fd, counter);
	else if (n == 13)
		ft_putchar_counter_fd('D', fd, counter);
	else if (n == 14)
		ft_putchar_counter_fd('E', fd, counter);
	else if (n == 15)
		ft_putchar_counter_fd('F', fd, counter);
}

static void	ten_to_sixteen_low(unsigned long n, int fd, int *counter)
{
	if (n == 10)
		ft_putchar_counter_fd('a', fd, counter);
	else if (n == 11)
		ft_putchar_counter_fd('b', fd, counter);
	else if (n == 12)
		ft_putchar_counter_fd('c', fd, counter);
	else if (n == 13)
		ft_putchar_counter_fd('d', fd, counter);
	else if (n == 14)
		ft_putchar_counter_fd('e', fd, counter);
	else if (n == 15)
		ft_putchar_counter_fd('f', fd, counter);
}

void	ft_putnbr_hexa_fd(unsigned long n, int fd, int up, int *counter)
{
	if (n >= 0 && n <= 9)
	{
		n += '0';
		ft_putchar_counter_fd(n, fd, counter);
	}
	else if (n >= 10 && n < 16 && up == 0)
		ten_to_sixteen_low(n, fd, counter);
	else if (n >= 10 && n < 16 && up == 1)
		ten_to_sixteen_up(n, fd, counter);
	else
	{
		ft_putnbr_hexa_fd(n / 16, fd, up, counter);
		ft_putnbr_hexa_fd(n % 16, fd, up, counter);
	}
}

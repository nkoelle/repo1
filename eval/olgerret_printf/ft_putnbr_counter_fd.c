/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_counter_fd.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olgerret <olgerret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 07:39:03 by olgerret          #+#    #+#             */
/*   Updated: 2021/07/24 07:39:38 by olgerret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_counter_fd(int n, int fd, int *counter)
{
	if (n >= 0 && n <= 9)
	{
		n += '0';
		ft_putchar_counter_fd(n, fd, counter);
	}
	else if (n == -2147483648)
		ft_putstr_counter_fd("-2147483648", fd, counter);
	else if (n == 2147483647)
		ft_putstr_counter_fd("2147483647", fd, counter);
	else if (n < 0)
	{
		ft_putchar_counter_fd('-', fd, counter);
		ft_putnbr_counter_fd((n *= -1), fd, counter);
	}
	else
	{
		ft_putnbr_counter_fd(n / 10, fd, counter);
		ft_putnbr_counter_fd(n % 10, fd, counter);
	}
}

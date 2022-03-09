/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolle <nkolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 18:24:40 by nkolle            #+#    #+#             */
/*   Updated: 2021/09/15 14:28:07 by nkolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_ptrbase(
	unsigned long arg, unsigned int base, char *digits, int *counter)
{
	if (arg >= base)
	{
		ft_ptrbase(arg / base, base, digits, counter);
		ft_putchar(digits[arg % base], counter);
	}
}

void	ft_putptr(unsigned long arg, int *counter)
{
	ft_putstr ("0x", counter);
	ft_ptrbase(arg, 16, "123456789abcdef", counter);
}

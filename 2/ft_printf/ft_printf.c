/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolle <nkolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 16:42:56 by nkolle            #+#    #+#             */
/*   Updated: 2021/09/21 13:30:28 by nkolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
static void	ft_base(
	unsigned long arg, unsigned int base, char *digits, int *counter)
{
	if (arg >= base)
		ft_base(arg / base, base, digits, counter);
	ft_putchar(digits[arg % base], counter);
}

static void	ft_sbase(long arg, unsigned int base, char *digits, int *counter)
{
	if (arg < 0)
	{
		ft_putchar('-', counter);
		arg *= -1;
		ft_base(arg, base, digits, counter);
	}
	else
		ft_base(arg, base, digits, counter);
}

void	ft_check_type(va_list arg, char c, int *counter)
{
	if (c == 'c')
		ft_putchar(va_arg(arg, int), counter);
	if (c == 's')
		ft_putstr(va_arg(arg, char *), counter);
	if (c == 'p')
	{
		ft_putstr("0x", counter);
		ft_base(va_arg(arg, unsigned long), 16, "0123456789abcdef", counter);
	}
	if (c == 'd' || c == 'i')
		ft_sbase(va_arg(arg, int), 10, "0123456789", counter);
	if (c == 'u')
		ft_base(
			va_arg(arg, unsigned int), 10, "0123456789", counter);
	if (c == 'x')
		ft_base(
			va_arg(arg, unsigned int), 16, "0123456789abcdef", counter);
	if (c == 'X')
		ft_base(
			va_arg(arg, unsigned int), 16, "0123456789ABCDEF", counter);
}

int	ft_printf(const char *input, ...)
{
	va_list	arg;
	int		counter;
	int		i;	

	i = 0;
	counter = 0;
	va_start (arg, input);
	while (input[i])
	{
		if (input[i] != '%')
			ft_putchar(input[i], &counter);
		else if (input[i] == '%' && input[i + 1] == '%' && ++i)
			ft_putchar(input[i], &counter);
		else if (input[i] == '%')
			ft_check_type(arg, input[++i], &counter);
		i++;
	}
	va_end (arg);
	return (counter);
}

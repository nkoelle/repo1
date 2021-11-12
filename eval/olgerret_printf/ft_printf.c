/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolle <nkolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 07:38:43 by olgerret          #+#    #+#             */
/*   Updated: 2021/07/27 11:35:44 by nkolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	datatype_checker(int datatype, void *element, int *counter)
{
	if (datatype == 'c')
		ft_putchar_counter_fd((char)element, 1, counter);
	else if (datatype == 'd' || datatype == 'i')
		ft_putnbr_counter_fd((int)element, 1, counter);
	else if (datatype == 'p')
	{
		ft_putstr_counter_fd("0x", 1, counter);
		ft_putnbr_hexa_fd((unsigned long)element, 1, 0, counter);
	}
	else if (datatype == 's')
	{
		if (element == 0)
			ft_putstr_counter_fd("(null)", 1, counter);
		ft_putstr_counter_fd((char *)element, 1, counter);
	}
	else if (datatype == 'u')
		ft_putnbr_unsigned_fd((unsigned int)element, 1, counter);
	else if (datatype == 'x')
		ft_putnbr_hexa_fd((unsigned int)element, 1, 0, counter);
	else if (datatype == 'X')
		ft_putnbr_hexa_fd((unsigned int)element, 1, 1, counter);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		counter;

	va_start(args, str);
	counter = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			if (str[i + 1] == '%')
			{
				ft_putchar_counter_fd('%', 1, &counter);
				i++;
			}
			else
				datatype_checker(str[++i], va_arg(args, void *), &counter);
		}
		else
			ft_putchar_counter_fd(str[i], 1, &counter);
		i++;
	}
	va_end(args);
	return (counter);
}

int	main()
{
	char array[] = "sunflower";
	ft_printf("here is the sentence %s %c \n", array, 5, 3, s, c);
	return (0);
}

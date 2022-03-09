/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolle <nkolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 12:25:14 by nkolle            #+#    #+#             */
/*   Updated: 2021/09/21 13:30:42 by nkolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *input, ...);
void	ft_putchar(char c, int *counter);
void	ft_putstr(char *s, int *counter);
void	ft_putptr(unsigned long arg, int *counter);
#endif

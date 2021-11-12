/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olgerret <olgerret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 07:38:52 by olgerret          #+#    #+#             */
/*   Updated: 2021/07/24 07:39:47 by olgerret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdarg.h>

int		ft_printf(const char *str, ...);

void	ft_putchar_counter_fd(char c, int fd, int *counter);
void	ft_putnbr_counter_fd(int n, int fd, int *counter);
void	ft_putstr_counter_fd(char *s, int fd, int *counter);

void	ft_putnbr_hexa_fd(unsigned long n, int fd, int up, int *counter);
void	ft_putnbr_unsigned_fd(unsigned int n, int fd, int *counter);

#endif

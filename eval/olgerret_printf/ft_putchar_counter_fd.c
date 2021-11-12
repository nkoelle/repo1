/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_counter_fd.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olgerret <olgerret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 07:38:57 by olgerret          #+#    #+#             */
/*   Updated: 2021/07/24 07:39:39 by olgerret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_counter_fd(char c, int fd, int *counter)
{
	write(fd, &c, fd);
	*counter += 1;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolle <nkolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 16:33:41 by nkolle            #+#    #+#             */
/*   Updated: 2022/02/18 14:06:39 by nkolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <signal.h>

// typedef void	(*sighandler_t)(int);
void	ft_putnbr_fd(int n, int fd);
int		ft_atoi(const char *str);
//char	convert_str(char buf[8]);

#endif

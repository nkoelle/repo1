/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolle <nkolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 14:46:35 by nkolle            #+#    #+#             */
/*   Updated: 2022/02/21 16:09:29 by nkolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# define BUFFER_SIZE 1

char	*get_next_line(int fd);
int		ft_strchr_gnl(const char *s, int c);
char	*ft_substr(char *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen2(const char *s1);

#endif

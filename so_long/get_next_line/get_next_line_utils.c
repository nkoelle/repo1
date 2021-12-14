/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolle <nkolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 14:46:41 by nkolle            #+#    #+#             */
/*   Updated: 2021/12/08 14:21:44 by nkolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strchr_gnl(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	while (*str != (char)c)
	{
		if ((char)c == '\0' && *str == '\0')
			return (1);
		if (*str == '\0' && (char)c != '\0')
			return (0);
		str++;
	}
	return (1);
}

char	*ft_substr_gnl(char *s, unsigned int start, size_t len)
{
	char	*sub;
	char	*s_cast;
	size_t	i;

	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen_gnl(s))
		len = 0;
	if (len > ft_strlen_gnl(s))
		len = ft_strlen_gnl(s) - start;
	s_cast = (char *)s;
	s_cast += start;
	sub = (char *) malloc(sizeof(char) * (len + 1));
	if (sub == NULL)
		return (NULL);
	i = 0;
	while (i < len && s[start + i] != '\0')
		sub[i++] = *s_cast++;
	sub[i] = '\0';
	return (sub);
}

size_t	ft_strlen_gnl(const char *s)
{
	size_t	i;

	i = 0;
	while (*s != '\0')
	{
		s++;
		i++;
	}
	return (i);
}

size_t	ft_strlen2(const char *s)
{
	size_t	i;

	i = 0;
	while (*s && *s != '\n')
	{
		s++;
		i++;
	}
	return (i);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*ptr;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	ptr = (char *)malloc(sizeof(*ptr) * (ft_strlen_gnl(s1)
				+ ft_strlen_gnl(s2) + 1));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1 && s1[j] != '\0')
		ptr[i++] = s1[j++];
	j = 0;
	while (s2[j] != '\0')
		ptr[i++] = s2[j++];
	ptr[i] = '\0';
	if (s1)
		free(s1);
	if (s2)
		free(s2);
	return (ptr);
}

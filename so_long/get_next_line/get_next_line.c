/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolle <nkolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 14:45:52 by nkolle            #+#    #+#             */
/*   Updated: 2021/12/08 14:18:33 by nkolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_protect(char **buf, int fd)
{
	if (fd < 0 || fd > 10240 || BUFFER_SIZE < 1)
		return (1);
	if (*buf == NULL)
	{
		*buf = malloc(sizeof (char *) * (BUFFER_SIZE + 1));
		if (*buf == NULL)
			return (1);
		*buf[0] = '\0';
	}
	return (0);
}

char	*ft_buf_update(char *buf)
{
	char	*temp;

	temp = ft_substr_gnl(buf, ft_strlen2(buf) + 1, ft_strlen_gnl(buf));
	if (buf)
		free (buf);
	return (temp);
}

int	ft_read_new_string(char **new_line, int fd)
{
	int	ret;

	*new_line = malloc(sizeof (char *) * (BUFFER_SIZE + 1));
	ret = read(fd, *new_line, BUFFER_SIZE);
	if (ret >= 0)
		(*new_line)[ret] = '\0';
	return (ret);
}

char	*ft_safe(char **buf, char **new_line, int by_co)
{
	if (*buf[0] == '\0')
	{
		if (*new_line)
			free(*new_line);
		free(*buf);
		*buf = NULL;
		return (NULL);
	}
	if (by_co == -1)
	{
		free(*buf);
		free(*new_line);
		return (NULL);
	}
	if (*new_line)
		free(*new_line);
	*new_line = ft_substr_gnl(*buf, 0, ft_strlen_gnl(*buf));
	*buf[0] = '\0';
	return (*new_line);
}

char	*get_next_line(int fd)
{
	static char		*buf = NULL;
	char			*new_line;
	int				by_co;

	by_co = 0;
	if (ft_protect(&buf, fd))
		return (NULL);
	while (1)
	{
		if (ft_strchr_gnl(buf, '\n') == 1)
		{
			new_line = ft_substr_gnl(buf, 0, ft_strlen2(buf) + 1);
			buf = ft_buf_update(buf);
			return (new_line);
		}
		else
		{
			by_co = ft_read_new_string(&new_line, fd);
			if (by_co == 0 || by_co == -1)
				return (ft_safe(&buf, &new_line, by_co));
			buf = ft_strjoin_gnl(buf, new_line);
			new_line = NULL;
		}
	}
}

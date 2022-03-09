/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolle <nkolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 16:58:11 by nkolle            #+#    #+#             */
/*   Updated: 2022/01/17 15:28:29 by nkolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_separate_b(char **readbuffer, int i)
{
	char	*line;
	char	*tempbuf;

	line = ft_substr(*readbuffer, 0, i);
	tempbuf = ft_strdup((*readbuffer) + i + 1);
	free (*readbuffer);
	*readbuffer = tempbuf;
	if ((*readbuffer)[0] == '\0')
	{
		free (tempbuf);
		*readbuffer = NULL;
	}
	return (line);
}

static char	*ft_rearrange_b(char *buff, char **readbuffer, ssize_t bytesread)
{
	char	*tempbuf;
	char	*ret;
	int		i;

	if (*readbuffer == NULL)
		*readbuffer = ft_strdup(buff);
	else if (bytesread != 0)
	{
		tempbuf = ft_strdup(*readbuffer);
		free (*readbuffer);
		*readbuffer = ft_strjoin(tempbuf, buff);
		free (tempbuf);
	}
	i = 0;
	while ((*readbuffer)[i] != '\n' && (*readbuffer)[i] != '\0')
		i++;
	if ((*readbuffer)[i] == '\n')
	{
		ret = ft_separate_b(readbuffer, i);
		if (ret)
			return (ret);
	}
	return (NULL);
}

static char	*ft_check_ifn(char **readbuffer)
{
	int		i;
	char	*line;
	char	*rest;

	i = 0;
	while ((*readbuffer)[i] != '\n' && (*readbuffer)[i] != '\0')
		i++;
	if ((*readbuffer)[0] == '\0')
	{
		free (*readbuffer);
		*readbuffer = NULL;
	}
	else if ((*readbuffer)[i] == '\n')
	{
		line = ft_substr(*readbuffer, 0, i);
		rest = ft_strdup((*readbuffer) + i + 1);
		free (*readbuffer);
		*readbuffer = rest;
		return (line);
	}
	return (NULL);
}

static int	ft_init_read(int fd, char *buff, char **readbuffer)
{
	int	bytesread;

	if (BUFFER_SIZE < 1)
		return (-1);
	bytesread = read(fd, buff, BUFFER_SIZE);
	if (bytesread == -1)
		return (bytesread);
	(buff)[bytesread] = '\0';
	if ((buff)[0] == '\0' && *readbuffer == NULL)
		bytesread = -1;
	return (bytesread);
}

char	*get_next_line(int fd)
{
	static char		*readbuffer[10240];
	char			buff[BUFFER_SIZE + 1];
	char			*line;
	ssize_t			bytesread;

	while (1)
	{
		if (readbuffer[fd])
		{
			line = ft_check_ifn(&readbuffer[fd]);
			if (line != NULL)
				return (line);
		}
		bytesread = ft_init_read(fd, buff, &readbuffer[fd]);
		if (bytesread == -1 || fd < 0)
			return (NULL);
		line = ft_rearrange_b(buff, &readbuffer[fd], bytesread);
		if (line != NULL)
			return (line);
		if (bytesread == 0 && readbuffer[fd] != NULL)
			return (ft_eof(&line, &readbuffer[fd]));
	}
	return (NULL);
}

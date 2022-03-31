/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolle <nkolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 15:48:33 by nkolle            #+#    #+#             */
/*   Updated: 2022/03/30 15:48:43 by nkolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*skip_whitespace(char *line_comb)
{
	char	*buf;
	
	while(*line_comb == (int)32 || *line_comb == (int)9)
		(*line_comb)++;
	buf = ft_strdup(line_comb);
	free(line_comb);
	return(buf);
}

int	check_for_str(char *s, char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == str[j] && s[i++] == str[j++] && s[i++] != '\0')
			return(1);
		i++;
	}
	return (0);
}

int	check_for_c(const char *s, int c)
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
	return (0);
}
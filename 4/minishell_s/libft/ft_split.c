/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolle <nkolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 16:29:57 by nkolle            #+#    #+#             */
/*   Updated: 2022/03/30 16:19:15 by nkolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	find_subs(char const *s, char c)
{
	int		i;
	int		wordcount;

	i = 0;
	wordcount = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i + 1] != c)
			wordcount++;
		i++;
	}
	return (wordcount);
}

static void	unwind(char **ptr_tab, int n)
{
	int		i;

	i = 0;
	while (i < n)
	{
		free(ptr_tab[i]);
		i++;
	}
}

static int	fill_tab(char **ptr_tab, char *ptr, char c, int wordcount)
{
	int		i;
	int		j;
	int		start;
	int		flag;

	flag = 1;
	i = 0;
	while (i < wordcount)
	{
		j = 0;
		while (ptr[j] == c)
			j++;
		if (flag == 1)
			start = j;
		while (ptr[j] != 0)
		{
			if (ptr[j] == '"' && flag == 1)
				flag *= -1;
			if (ptr[j] == '"' && flag == -1)
				flag *= -1;
			if (ptr[j] == c && flag == -1)
				j++;
			if (ptr[j] == c && flag == 1)
				break ;
			j++;
		}
		ptr_tab[i] = (char *)malloc((j - start + 1) * sizeof(char));
		if (ptr_tab[i] == 0 || flag == -1)
		{
			unwind(ptr_tab, i);
			return (0);
		}
		ft_strlcpy(ptr_tab[i], &ptr[start], j - start + 1);
		ptr = &ptr[j];
		i++;
	}
	ptr_tab[wordcount] = 0;
	return (1);
}


char	**ft_split(char const *s, char c)
{
	int		wordcount;
	char	**ptr_tab;
	char	*ptr;

	if (!s)
		return (NULL);
	wordcount = find_subs(s, c);
	ptr_tab = (char **)malloc((wordcount + 1) * sizeof(char *));
	if (!ptr_tab)
		return (NULL);
	ptr = (char *)s;
	if (!fill_tab(ptr_tab, ptr, c, wordcount))
	{
		free(ptr_tab);
		return (NULL);
	}
	return (ptr_tab);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolle <nkolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 13:55:11 by nmichael          #+#    #+#             */
/*   Updated: 2022/08/04 20:35:13 by nkolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_txt(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return ;
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

int	ft_env(t_env *env)
{
	while (env)
	{
		printf("%s", env->name);
		printf("%s\n", env->value);
		env = env->next;
	}
	return (SUCCESS);
}

int	singlerd_hlp(char **line_comb)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	if (*line_comb)
	{
		while ((*line_comb)[i])
		{
			if ((*line_comb)[i] == '\'')
			{
				flag = 1;
				return (3);
			}
			i++;
		}
	}
	printf("Quote required!\n");
	return (4);
}

int	singlerd_hlp2(char **line_comb)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	if (*line_comb)
	{
		while ((*line_comb)[i])
		{
			if ((*line_comb)[i] == '"')
			{
				flag = 1;
				return (3);
			}
			i++;
		}
	}
	printf("Quote required!\n");
	return (4);
}

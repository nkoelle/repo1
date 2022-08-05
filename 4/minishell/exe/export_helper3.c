/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_helper3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolle <nkolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 22:02:23 by nkolle            #+#    #+#             */
/*   Updated: 2022/08/04 22:49:07 by nkolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	init_exlcls(t_exp_locals *lcls)
{
	lcls->i = 0;
	lcls->k = 0;
	lcls->j = 0;
	lcls->expanded = malloc(sizeof(char *) * (100));
}

void	fill_exp(t_exp_locals *lcls, t_env2 *env2, char *str)
{
	while (42)
	{
		lcls->i++;
		if (str[lcls->i] == ' ' || str[lcls->i] == '\0' || str[lcls->i] == '$')
		{
			lcls->dollarstr = ft_substr(str, (lcls->k + 1),
					(lcls->i - lcls->k - 1));
			if (ft_getenv2(lcls->dollarstr, env2) == 0)
				return ;
			else
			{
				lcls->expanded[lcls->j] = ft_strdup(ft_getenv(lcls->dollarstr,
							env2));
				free(lcls->dollarstr);
				lcls->j++;
				return ;
			}
		}
	}
}

int	ft_getenv2(char *name, t_env2 *env)
{
	while (env)
	{
		if (ft_strncmp(name, env->name_hidden,
				env_size(name, env->name_hidden)) == 0)
			return (1);
		env = env->next;
	}
	return (0);
}

void	ft_helop(char *buff, t_input tmp, int i)
{
	buff = ft_substr(tmp.cmd[i], 0, f_symb(tmp.cmd[i]));
	buff = ft_strjoin(buff, "$");
	tmp.cmd[i] = ft_substr(tmp.cmd[i],
			f_symb(tmp.cmd[i]) + 1, ft_strlen(tmp.cmd[i]));
	tmp.cmd[i] = ft_strjoin(buff, tmp.cmd[i]);
}

char	*ft_getenv(char *name, t_env2 *env)
{
	while (env)
	{
		if (ft_strncmp(name, env->name_hidden,
				env_size(name, env->name_hidden)) == 0)
			return (ft_strdup(env->value_hidden));
		env = env->next;
	}
	return (NULL);
}

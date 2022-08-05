/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolle <nkolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 12:37:12 by nkolle            #+#    #+#             */
/*   Updated: 2022/08/03 13:09:11 by nkolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	uns_help1(t_env2 *tmp2, t_input **input, t_env2 *env2_buf)
{
	if (ft_strncmp((*input)->cmd[1], env2_buf->next->name_hidden,
			env_size((*input)->cmd[1], env2_buf->next->name_hidden)) == 0)
	{
		tmp2 = env2_buf->next->next;
		free_node2(env2_buf->next);
		env2_buf->next = tmp2;
	}
}

void	uns_help2(t_env *tmp, t_input **input, t_env *env_buf)
{
	if (ft_strncmp((*input)->cmd[1], env_buf->next->name,
			env_size((*input)->cmd[1], env_buf->next->name)) == 0)
	{
		tmp = env_buf->next->next;
		free_node(env_buf->next);
		env_buf->next = tmp;
	}
}

void	uns_help3(t_env *tmp, t_env **env)
{
	tmp = (*env)->next;
	free_node((*env));
	(*env) = tmp;
}

void	uns_help4(t_env2 *tmp2, t_env2 **env2)
{
	tmp2 = (*env2)->next;
	free_node2((*env2));
	(*env2) = tmp2;
}

void	init_lcls(t_unset_locals *locals, t_env **env, t_env2 **env2)
{
	locals->env_buf = *env;
	locals->env2_buf = *env2;
	locals->tmp2 = NULL;
	locals->tmp = NULL;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolle <nkolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 13:07:15 by nmichael          #+#    #+#             */
/*   Updated: 2022/08/03 13:07:46 by nkolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	env_size(char *str1, char *str2)
{
	int	str1_len;
	int	str2_len;

	str1_len = 0;
	while (str1 && str1[str1_len] && str1[str1_len] != '=')
		str1_len++;
	str2_len = 0;
	while (str2 && str2[str2_len] && str2[str2_len] != '=')
		str2_len++;
	if (str1_len > str2_len)
		return (str1_len);
	return (str2_len);
}

void	*ft_memdel(void *ptr)
{
	if (ptr)
	{
		free(ptr);
		ptr = NULL;
	}
	return (NULL);
}

void	free_node(t_env *env)
{
	env->value = ft_memdel(env->value);
	env->name = ft_memdel(env->name);
	env = ft_memdel(env);
}

void	free_node2(t_env2 *env2)
{
	env2->value_hidden = ft_memdel(env2->value_hidden);
	env2->name_hidden = ft_memdel(env2->name_hidden);
	env2 = ft_memdel(env2);
}

int	ft_unset(t_env **env, t_env2 **env2, t_input **input)
{
	t_unset_locals	locals;

	init_lcls(&locals, env, env2);
	if ((*input)->cmd[1] == NULL)
		return (1);
	if (ft_strncmp((*input)->cmd[1], (*env)->name,
			env_size((*input)->cmd[1], (*env)->name)) == 0)
		uns_help3(locals.tmp, env);
	while (locals.env_buf && locals.env_buf->next)
	{
		uns_help2(locals.tmp, input, locals.env_buf);
		locals.env_buf = locals.env_buf->next;
	}
	if (ft_strncmp((*input)->cmd[1], (*env2)->name_hidden,
			env_size((*input)->cmd[1], (*env2)->name_hidden)) == 0)
		uns_help4(locals.tmp2, env2);
	while (locals.env2_buf && locals.env2_buf->next)
	{
		uns_help1(locals.tmp2, input, locals.env2_buf);
		locals.env2_buf = locals.env2_buf->next;
	}
	return (SUCCESS);
}

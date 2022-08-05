/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_helper2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolle <nkolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 13:50:38 by nkolle            #+#    #+#             */
/*   Updated: 2022/08/03 14:00:24 by nkolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	env_add_hidden_2(t_env2 **env_struct2, char *cmd)
{
	t_env2	*new;
	int		i;

	i = 0;
	new = ft_calloc(1, sizeof(t_env2));
	new->name_hidden = ft_substr(&cmd[i], 0, env_break2(&cmd[i]));
	new->value_hidden = ft_substr(&cmd[i], env_break(&cmd[i]) + 1,
			env_start(&cmd[i]));
	new->hidden = true;
	new->next = NULL;
	ft_lstadd_back_env_hd(env_struct2, new);
	return (SUCCESS);
}

int	env_add_hidden_3(t_env2 **env_struct2, char *cmd)
{
	t_env2	*new;
	int		i;

	i = 0;
	new = ft_calloc(1, sizeof(t_env2));
	new->name_hidden = ft_substr(&cmd[i], 0, ft_strlen(&cmd[i]));
	new->hidden = true;
	new->next = NULL;
	ft_lstadd_back_env_hd(env_struct2, new);
	return (SUCCESS);
}

void	init_locals(t_exe_locals *locals)
{
	locals->i = 0;
	locals->j = 0;
	locals->fd_in = STDIN_FILENO;
	locals->fd_out = STDOUT_FILENO;
	locals->fd_next = 0;
	locals->fd_standard_in = dup(STDIN_FILENO);
	locals->fd_standard_out = dup(STDOUT_FILENO);
	locals->flag_previous_pipe = 0;
	locals->exit_status = 0;
}

int	str_count(t_input **input)
{
	t_env	*temp;
	int		i;

	temp = (*(*input)->env);
	i = 0;
	while (temp)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}

char	**char_converter(t_input **input)
{
	int		i;
	int		j;
	char	*str;
	char	**arr;
	t_env	*env;

	i = 0;
	j = str_count(input);
	env = *((*input)->env);
	arr = ft_calloc(sizeof(char *), j + 1);
	while (env)
	{
		j = 0;
		str = ft_strjoin(env->name, env->value);
		j = ft_strlen(str);
		arr[i] = ft_calloc(sizeof(char), j);
		arr[i] = ft_strdup(str);
		env = env->next;
		i++;
	}
	arr[i] = NULL;
	return (arr);
}

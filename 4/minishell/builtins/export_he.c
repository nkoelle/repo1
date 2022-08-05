/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_he.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmichael <nmichael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 14:07:59 by nmichael          #+#    #+#             */
/*   Updated: 2022/08/03 18:31:40 by nmichael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	print_error(int error, char *arg)
{
	int	i;

	if (error == -1)
		ft_putstr_fd ("export: not valid in this context: ", STDERR);
	else if (error == 0 || error == -3)
		ft_putstr_fd ("export: not a valid identifier: ", STDERR);
	i = 0;
	while (arg[i] && (arg[i] != '=' || error == -3))
	{
		write (STDERR, &arg[i], 1);
		i++;
	}
	write (STDERR, "\n", 1);
	return (ERROR);
}

int	is_valid_env(char *envp)
{
	int	i;

	i = 0;
	if (ft_isdigit(envp[i]) == 1)
		return (0);
	if (!envp[2])
		return (3);
	while (envp[i] && envp[i] != '=')
	{
		if (ft_isalnum(envp[i]) == 0)
			return (-1);
		i++;
	}
	if (envp[i] != '=')
		return (2);
	return (1);
}

int	env_add(t_env **env_struct, char *cmd)
{
	t_env	*new;
	int		i;

	i = 0;
	new = ft_calloc(1, sizeof(t_env));
	new->name = ft_substr(&cmd[i], 0, env_break(&cmd[i]));
	new->value = ft_substr(&cmd[i], env_break(&cmd[i]),
			env_start(&cmd[i]));
	new->hidden = false;
	new->next = NULL;
	ft_lstadd_back_env(env_struct, new);
	i++;
	return (0);
}

int	ft_export(t_env *env, t_env2 *env2, t_input **input)
{
	int	error_env;
	int	i;
	int	flag;

	error_env = 0;
	flag = 0;
	i = 0;
	if (!(*input)->cmd[1])
		print4(env2);
	while ((*input)->cmd[++i])
	{
		if (is_already_in_env((*input)->cmd[i], env2))
			flag = export_norm(env, env2, input, &i);
		error_env = is_valid_env((*input)->cmd[i]);
		if (error_env <= 0)
			return (print_error(error_env, (*input)->cmd[i]));
		if (error_env == 1 && flag == 0)
			export_norm2(env, env2, input, &i);
		if (error_env == 2 && flag == 0)
			env_add_hidden_3(&env2, (*input)->cmd[i]);
		flag = 0;
	}
	return (SUCCESS);
}

int	f_symb(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '#')
		i++;
	return (i);
}

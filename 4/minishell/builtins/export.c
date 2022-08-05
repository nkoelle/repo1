/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmichael <nmichael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 13:07:09 by nmichael          #+#    #+#             */
/*   Updated: 2022/08/03 16:46:16 by nmichael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*get_env_value(char *cmd)
{
	char	*env_value;
	int		env_length;
	char	*cmd_at_equals;
	int		i;

	cmd_at_equals = ft_strrchr(cmd, '=');
	if (cmd_at_equals == NULL)
		return (NULL);
	env_length = ft_strlen(cmd_at_equals);
	env_value = ft_calloc(env_length, sizeof(*env_value));
	if (env_value == NULL)
		return (NULL);
	i = 0;
	while (i < env_length)
	{
		env_value[i] = cmd_at_equals[i];
		++i;
	}
	return (env_value);
}

char	*get_env_name(char *cmd)
{
	char	*env_name;

	env_name = ft_substr(cmd, 0, ft_strrchr(cmd, '=') - cmd);
	if (env_name == NULL)
		return (NULL);
	return (env_name);
}

bool	is_already_in_env(char *cmd, t_env2 *hidden_env)
{
	t_env2	*hidden_env_tmp;
	char	*env_name;
	int		length;

	env_name = get_env_name(cmd);
	hidden_env_tmp = hidden_env;
	while (hidden_env_tmp)
	{
		if (ft_strlen(hidden_env_tmp->name_hidden) > ft_strlen(env_name))
			length = ft_strlen(hidden_env_tmp->name_hidden);
		else
			length = ft_strlen(env_name);
		if (ft_strncmp(hidden_env_tmp->name_hidden, env_name,
				length) == 0)
		{
			free(env_name);
			return (true);
		}
		hidden_env_tmp = hidden_env_tmp->next;
	}
	free(env_name);
	return (false);
}

bool	is_already_in_env2(char *cmd, t_env *hidden_env)
{
	t_env	*hidden_env_tmp;
	char	*env_name;
	int		length;

	env_name = get_env_name(cmd);
	hidden_env_tmp = hidden_env;
	while (hidden_env_tmp)
	{
		if (ft_strlen(hidden_env_tmp->name) > ft_strlen(env_name))
			length = ft_strlen(hidden_env_tmp->name);
		else
			length = ft_strlen(env_name);
		if (ft_strncmp(hidden_env_tmp->name, env_name,
				length) == 0)
		{
			free(env_name);
			return (false);
		}
		hidden_env_tmp = hidden_env_tmp->next;
	}
	free(env_name);
	return (true);
}

void	overwrite_value(char *cmd, t_env *env, t_env2 *hidden_env)
{
	t_helpi	helpi;

	init_helpi(cmd, &helpi, env);
	while (helpi.tmp_env)
	{
		if (ft_strncmp(helpi.tmp_env->name,
				helpi.env_name, ft_strlen(helpi.env_name)) == 0)
		{
			free(helpi.tmp_env->value);
			helpi.tmp_env->value = ft_strdup(helpi.env_value);
			break ;
		}
		helpi.tmp_env = helpi.tmp_env->next;
	}
	helpi.tmp_hidden_env = hidden_env;
	over_helper(&helpi);
	free(helpi.env_name);
	free(helpi.env_value);
}

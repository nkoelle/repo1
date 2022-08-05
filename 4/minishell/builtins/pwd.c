/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmichael <nmichael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 16:44:55 by nmichael          #+#    #+#             */
/*   Updated: 2022/08/03 16:44:59 by nmichael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_pwd(void)
{
	char	cwd[PATH_MAX];

	if (getcwd(cwd, PATH_MAX))
	{
		ft_putendl_fd(cwd, 1);
		return (SUCCESS);
	}
	else
		return (ERROR);
}

void	init_helpi(char *cmd, t_helpi *helpi, t_env *env)
{
	helpi->env_name = get_env_name(cmd);
	helpi->env_value = get_env_value(cmd);
	helpi->tmp_env = env;
}

void	over_helper(t_helpi *helpi)
{
	while (helpi->tmp_hidden_env)
	{
		if (ft_strncmp(helpi->tmp_hidden_env->name_hidden, helpi->env_name,
				ft_strlen(helpi->env_name)) == 0)
		{
			free(helpi->tmp_hidden_env->value_hidden);
			helpi->tmp_hidden_env->value_hidden = ft_substr(helpi->env_value,
					1, ft_strlen(helpi->env_value));
			break ;
		}
		helpi->tmp_hidden_env = helpi->tmp_hidden_env->next;
	}
}

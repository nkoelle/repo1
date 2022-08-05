/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmichael <nmichael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 17:02:54 by nkolle            #+#    #+#             */
/*   Updated: 2022/08/04 21:44:56 by nmichael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	protected_close(int fd)
{
	if (fd != STDIN_FILENO && fd != STDOUT_FILENO)
		close (fd);
}

void	converte_buff(t_input *input, int *i)
{
	int	j;

	j = 0;
	free(input->cmd[*i]);
	input->cmd[*i] = "";
	while (input->buff[j] != NULL)
	{
		input->cmd[*i] = ft_strjoin(input->cmd[*i], input->buff[j]);
		free(input->buff[j]);
		j++;
	}
}

int	export_norm(t_env *env, t_env2 *env2, t_input **input, int *i)
{
	if (ft_strchr((*input)->cmd[1], '=') != 0)
		overwrite_value((*input)->cmd[*i], env, env2);
	if (is_already_in_env2((*input)->cmd[*i], env)
		&& ft_strchr((*input)->cmd[1], '=') != 0)
		env_add(&env, (*input)->cmd[*i]);
	return (1);
}

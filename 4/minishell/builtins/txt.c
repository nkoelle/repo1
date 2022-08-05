/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   txt.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolle <nkolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 14:00:37 by nmichael          #+#    #+#             */
/*   Updated: 2022/08/03 16:10:15 by nkolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	print4(t_env2 *input)
{
	while (input)
	{
		printf("declare -x %s", input->name_hidden);
		if ((input->value_hidden))
		{
			printf("=\"%s", input->value_hidden);
			printf("\"");
			printf("\n");
		}
		else
			printf("\n");
		input = input->next;
	}
}

void	print5(t_env *input)
{
	while (input)
	{
		printf("%s", input->name);
		printf("%s\n", input->value);
		input = input->next;
	}
}

void	export_norm2(t_env *env, t_env2 *env2, t_input **input, int *i)
{
	env_add(&env, (*input)->cmd[*i]);
	env_add_hidden_2(&env2, (*input)->cmd[*i]);
}

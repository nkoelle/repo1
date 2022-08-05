/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmichael <nmichael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 16:49:55 by nmichael          #+#    #+#             */
/*   Updated: 2022/08/04 22:53:05 by nmichael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	find_breaking_char(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isalnum(str[i]) == 0 && str[i] != '_')
			break ;
		i++;
	}
	return (i);
}

void	init_check(t_check *ck)
{
	ck->i = 0;
	ck->buff = NULL;
}

void	check_for_dollar(t_input *input, t_env2 *env2)
{
	t_input	*tmp;
	t_check	ck;

	tmp = input;
	init_check(&ck);
	while (tmp->cmd[ck.i])
	{
		if (ft_strrchr(tmp->cmd[ck.i], '$'))
		{
			if (*(ft_strrchr(tmp->cmd[ck.i], '$') + 1) == '?')
			{
				free(tmp->cmd[ck.i]);
				tmp->cmd[ck.i] = ft_itoa(get_err_code());
			}
			else
			{
				input->buff = get_dollar_in_quotes(env2, tmp->cmd[ck.i]);
				converte_buff(input, &ck.i);
			}
		}
		while (ft_strchr(tmp->cmd[ck.i], '#'))
			ft_helop(ck.buff, *tmp, ck.i);
		ck.i++;
	}
}

char	**get_dollar_in_quotes(t_env2 *env2, char *str)
{
	t_exp_locals	lcls;

	init_exlcls(&lcls);
	while (str[lcls.i])
	{
		lcls.k = lcls.i;
		if (str[lcls.i] == '#')
			str[lcls.i] = '$';
		while (str[lcls.i] && (str[lcls.i] != '$'))
			lcls.i++;
		lcls.expanded[lcls.j] = ft_substr(str, lcls.k, (lcls.i - lcls.k));
		lcls.k = lcls.i;
		lcls.j++;
		if (str[lcls.i] && (str[lcls.i] == '$'))
			fill_exp(&lcls, env2, str);
	}
	lcls.expanded[lcls.j + 1] = NULL;
	return (lcls.expanded);
}

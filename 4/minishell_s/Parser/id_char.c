/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   id_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolle <nkolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 15:55:15 by nkolle            #+#    #+#             */
/*   Updated: 2022/03/31 14:29:53 by nkolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*id_char(char *line_comb)
{
	t_buffer	*temp;
	char		*ret_str;

	temp = NULL;
	temp = malloc(sizeof(t_buffer));
	while (is_breaking_char(&line_comb) == false)
		add_char_to_list(&temp, *line_comb);
	ret_str = ft_strdup(temp->content);
	free_list(temp);
	return (ret_str);
}

bool	is_breaking_char(char **line_comb)
{
	if (**line_comb == '<' ||**line_comb == '>' || **line_comb == '|' 
		|| **line_comb == ' ' || **line_comb == (int)9 || **line_comb == '\n' 
		|| **line_comb == '\0')
		return (true);
	return (false);

// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   handle_special_char.c                              :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: nkolle <nkolle@student.42.fr>              +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2022/03/08 15:36:10 by nkolle            #+#    #+#             */
// /*   Updated: 2022/03/09 17:26:42 by nkolle           ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include "../minishell.h"

void	read_single_quoted(char **line_comb, t_buffer **buffer)
{
	while (**line_comb != '\'' && **line_comb != '\0')
	{
		stringbuffer_append_char(buffer, **line_comb);
		(*line_comb)++;
	}
}

void	read_double_quoted(char **line_comb, t_buffer **buffer)
{
	while (**line_comb != '"')
	{
		stringbuffer_append_char(buffer, **line_comb);
		(*line_comb)++;
	}
}

int	is_breaking_char(char **line_comb) //nochmal anschauen welche abbrechen
{
	if (**line_comb == '<' ||**line_comb == '>' || **line_comb == '|' 
		|| **line_comb == ' ' || **line_comb == (int)9 || **line_comb == '\n' || **line_comb == '\0')

		return(1);
	return (0);
}

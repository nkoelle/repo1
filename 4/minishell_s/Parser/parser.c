/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolle <nkolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 15:45:26 by nkolle            #+#    #+#             */
/*   Updated: 2022/03/30 19:17:56 by nkolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	parser(char *line_comb, t_input **input, t_buffer **buffer, t_operator **operator)
{
	if (check_for_str(line_comb, "<<"))
	{
		line_comb = skip_whitespace(line_comb);
		//add_str_to_op_list(operator, HEREDOC, read_identifier(&line_comb));
	}
	else if (check_for_str(line_comb, ">>"))
	{
		skip_whitespace(line_comb);
		//add_str_to_op_list(operator, OUT_APPEND, read_identifier(&line_comb));
	}
	else if (check_for_c(line_comb, (int)60))
	{
		skip_whitespace(line_comb);
		//add_str_to_op_list(operator, INFILE, read_identifier(&line_comb));
	}
	else if (check_for_c(line_comb, (int)62))
	{
		skip_whitespace(line_comb);
		//add_str_to_op_list(operator, OUT_TRUNCATE, read_identifier(&line_comb));
	}
	else
		add_str_to_buf_list(buffer, id_char(&line_comb));
	//add_string_to_input_list -> cmd
}
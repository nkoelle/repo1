/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolle <nkolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 20:02:18 by nkolle            #+#    #+#             */
/*   Updated: 2022/08/04 21:42:44 by nkolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	parser(
		char *line_comb, t_buffer **buffer, t_input **input, t_env **env)
{
	t_operator	*operator;
	int			pos;

	pos = 0;
	operator = NULL;
	while (*line_comb)
	{
		parser_helper(&line_comb, &operator, &pos);
		if (check_for_str(line_comb, "|"))
		{
			line_comb++;
			pos++;
			helper_4(input, &operator, buffer, env);
		}
		if (operator != NULL && *line_comb == '\0' && operator->flag == 0)
			create_op_files(&operator);
		else
			fck_norm5(&line_comb, buffer);
	}
	if ((*buffer) || operator)
		append_linked_list_to_input(input, &operator, buffer, env);
}

void	fck_norm1(char **line_comb, t_operator	**operator, int *pos)
{
	*line_comb = *line_comb + 2;
	skip_whitespace(line_comb);
	append_string_to_redirection_list(
		operator, HEREDOC, read_identifier(line_comb), pos);
}

void	fck_norm2(char **line_comb, t_operator	**operator, int *pos)
{
	*line_comb = *line_comb + 2;
	skip_whitespace(line_comb);
	append_string_to_redirection_list(
		operator, OUT_APPEND, read_identifier(line_comb), pos);
}

void	fck_norm3(char **line_comb, t_operator	**operator, int *pos)
{
	*line_comb = *line_comb + 2;
	skip_whitespace(line_comb);
	append_string_to_redirection_list(
		operator, INFILE, read_identifier(line_comb), pos);
}

void	fck_norm4(char **line_comb, t_operator	**operator, int *pos)
{
	*line_comb = *line_comb + 2;
	skip_whitespace(line_comb);
	append_string_to_redirection_list(
		operator, OUT_TRUNCATE, read_identifier(line_comb), pos);
}

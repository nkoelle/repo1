/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolle <nkolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 12:54:19 by nmichael          #+#    #+#             */
/*   Updated: 2022/03/31 14:53:13 by nkolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL
#define MINISHELL

#include "./libft/libft.h"
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

enum e_operator {
	NOTHING,
	INFILE, // <
	HEREDOC, // <<
	OUT_TRUNCATE, // >
	OUT_APPEND, // >>
};

typedef struct s_operator
{
	char				*content;
	enum e_operator		redir_type;
	struct s_operator	*next;
}	t_operator;

typedef struct s_buffer
{
	char				*content;
	struct s_buffer		*next;
}	t_buffer;

typedef struct s_input
{
	char				**cmd;
	struct s_operator	*redirections;
	struct s_input		*next;
}	t_input;

// -----Lexer----------------------------------------------
int		main(void);
void	save_line(void);
//------Parser--------------------------------------------
void	parser(char *line_comb, t_input **input, t_buffer **buffer, t_operator **operator);
char	*id_char(char *line_comb);
bool	is_breaking_char(char **line);
//------Utils----------------------------------------------
void	add_char_to_list(t_buffer **temp, char c);
void	add_str_to_buf_list(t_buffer **buffer, char *s);
//void	add_str_to_op_list(t_operator **operator, char c);
void	free_list(t_buffer *list);
t_buffer	*add_new_elem_to_buffer(t_buffer **buffer);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolle <nkolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 12:54:19 by nmichael          #+#    #+#             */
/*   Updated: 2022/03/14 19:19:17 by nkolle           ###   ########.fr       */
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

//-----Lexer----------------------------------------------
int		main(void);
void	save_line(void);
//------Parser--------------------------------------------
void	parser(char *line_comb, t_buffer **buffer, t_operator **operator);
int		check_for_str(char *s, char *str);
int		check_for_c(const char *s, int c);
char	*skip_whitespace(char *line_comb);
void	append_cmd_to_linked_list(t_input **cmd, t_buffer *buffer, t_operator *operator);
// 1.) read_identifier
char	*read_identifier(char **ptr);
// 1.1.) special_charhandling
void	read_single_quoted(char **ptr, t_buffer **buffer);
void	read_double_quoted(char **ptr, t_buffer **buffer);
int		is_breaking_char(char **ptr);
//-------Utils---------------------------------------------
// 1.) structurehandling
void		append_string_to_linked_list(t_buffer **buffer, char *content);
t_buffer	*new_element(char *content);
t_operator	*new_element_op(char *content, enum e_operator type);
void		append_string_to_redirection_list
			(t_operator **element, enum e_operator, char *content);
// 2.) read_id_utils
int			stringbuffer_append_char(t_buffer **buffer, char c);
char		*stringbuffer_create(t_buffer **buffer);
void		stringbuffer_destroy(t_buffer **buffer);
t_buffer	*stringbuffer_create_node(t_buffer **buffer);
void		stringbuffer_get_string(t_buffer **buffer, char **str);
// 3.) handle_list
void	ft_lstadd_back_op(t_operator **lst, t_operator *new);
void	ft_lstadd_back_buf(t_buffer **lst, t_buffer *new);
t_buffer	*ft_lstlast_buf(t_buffer *lst);
t_operator	*ft_lstlast_op(t_operator *lst);
//-------Executer--------------------------------------------

#endif
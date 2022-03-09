/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolle <nkolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 20:02:18 by nkolle            #+#    #+#             */
/*   Updated: 2022/03/04 16:09:15 by nkolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parser(char *line_comb,t_argv_list *element)
{
	char *ident;

	ident = NULL;
	if (check(line_comb, "<<"))
	{
		skip_whitespace(line_comb);
		append_string_to_redirection_list(&element, HEREDOC, read_identifier(line_comb));
	}
	else if (check(line_comb, ">>"))
	{
		skip_whitespace(line_comb);
		append_string_to_redirection_list(&element, OUT_APPEND, read_identifier(line_comb));
	}
	if (check(line_comb, "<"))

	// else if (check(line_comb, "|"))
	// {
	// 	clearen und die listen vor | und füge sie 
	// }
	else
	{
		append_string_to_linked_list(&element, read_identifier(line_comb));
	}
}







// typedef char** t_input_stream;

// char input_stream_peek(t_input_stream stream)
// {
//     return (*stream);
// }

// bool    input_stream_has_next(t_input_stream stream)
// {
//     return (input_stream_peek(stream) != '\0');
// }

// void    input_stream_advance(t_input_stream stream)
// {
//     (*stream)++;
// }

// void    read_single_quoted(char **line_comb, t_stringbuffer *buffer)
// {
//     while (**line_comb != '\'')
//     {
//         stringbuffer_append_char(buffer, **line_comb);
//         (*line_comb)++;
//     }
// }

// char *read_identifier(char **line_comb)
// {
//     t_stringbuffer  buffer;
//     char            *str;

//     stringbuffer_create(&buffer);
    
//     while (1)
//     {
//         if (**line_comb == '\'')
//             read_single_quoted(line_comb, &buffer);
//         else if (**line_comb == '"')
//             read_double_quoted(line_comb, &buffer);
//         else if (**line_comb == '$')
//         {
//             char *value = get_value(read_varname(line_comb)); 
//             stringbuffer_append_string(&buffer, value);
//         }
//         else if (is_breaking_char(**line_comb))
//         {
//             break ;
//         }
//         else
//         {
//             stringbuffer_append_char(&buffer, **line_comb);
//             input_stream_advance(stream);
//             (*line_comb)++;
//         }
//     }

//     stringbuffer_get_string(&buffer, &str);
//     stringbuffer_destroy(&buffer);
//     return (str);
// }

// void parse(char **line_comb)
// {
//     char *ident;
//     <skip_whitespace(line_comb);>
    
//     if (check(line_comb, "<<"))
//     {
//         skip_whitespace(line_comb);
//         append_string_to_redirection_list(&redirection_list, HEREDOC, read_identifier(line_comb));
//     }
//     else if (check(line_comb, ">>"))
//     {
//         skip_whitespace(line_comb);
//         append_string_to_redirection_list(&redirection_list, OUT_APPEND, read_identifier(line_comb));
//     }
//     if (check(line_comb, "<"))

//     else if (check(line_comb, "|"))
//     {
//         clearen und die listen vor | und füge sie 
//     }
//     else
//     {
//         append_string_to_linked_list(&argv_list, read_identifier(line_comb));
//     }
// }
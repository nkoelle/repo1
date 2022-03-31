/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolle <nkolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 20:02:18 by nkolle            #+#    #+#             */
/*   Updated: 2022/03/30 16:32:40 by nkolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*skip_whitespace(char *line_comb)
{
	char	*buf;
	
	while(*line_comb == (int)32 || *line_comb == (int)9)
		(*line_comb)++;
	buf = ft_strdup(line_comb);
	free(line_comb);
	return(buf);
}

int	check_for_str(char *s, char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == str[j] && s[i++] == str[j++] && s[i++] != '\0')
			return(1);
		i++;
	}
	return (0);
}

int	check_for_c(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	while (*str != (char)c)
	{
		if ((char)c == '\0' && *str == '\0')
			return (1);
		if (*str == '\0' && (char)c != '\0')
			return (0);
		str++;
	}
	return (0);
}

void	parser(char *line_comb, t_buffer **buffer, t_operator **operator)
{
		if (check_for_str(line_comb, "<<"))
		{
			line_comb = skip_whitespace(line_comb);
			// TODO: Heredoc spaeter endgueltig einlesen, das hier ist nur der String, bis zu dem eingelesenw erden soll
			append_string_to_redirection_list(operator, HEREDOC, read_identifier(&line_comb));
		}
		else if (check_for_str(line_comb, ">>"))
		{
			skip_whitespace(line_comb);
			append_string_to_redirection_list(operator, OUT_APPEND, read_identifier(&line_comb));
		
		else if (check_for_c(line_comb, (int)60))
		{
			skip_whitespace(line_comb);
			append_string_to_redirection_list(operator, INFILE, read_identifier(&line_comb));
		}
		else if (check_for_c(line_comb, (int)62))
		{
			skip_whitespace(line_comb);
			append_string_to_redirection_list(operator, OUT_TRUNCATE, read_identifier(&line_comb));
		}
		// else if (check_for_c(line_comb, (int)124))
		// {
		// 	append_cmd_to_linked_list(cmd, *buffer, *operator);
		// 	buffer = NULL;
		// 	operator = NULL;
		// }
		// else if (/* At end of string */)
		// {
		// 	append_cmd_to_linked_list(cmd, buffer, operator);
		// 	// Hier Heredoc einlesen 
		// 	return (cmd);
		// }
		else
		{
			append_string_to_linked_list(buffer, read_identifier(&line_comb));
		}
}

// void	append_cmd_to_linked_list(t_input **input, t_buffer *buffer, t_operator *operator)
// {
// 	int count;

// 	count = 0;
// 	while(operator->next)
// 	{
// 		t_input = operator[count];
// 		count++;
// 	}
// 	count = 0;
// 	while(buffer->next != NULL)
// 	{
// 		s_input.cmd = buffer[count];
// 		count++;
// 	}
// }

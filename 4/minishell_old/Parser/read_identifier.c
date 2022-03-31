// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   read_identifier.c                                  :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: nkolle <nkolle@student.42.fr>              +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2022/03/07 15:41:25 by nkolle            #+#    #+#             */
// /*   Updated: 2022/03/09 18:20:32 by nkolle           ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include "../minishell.h"
//suche den str bis operator, |, '\t, ' ' oder quotes "", '' und return den str

char *read_identifier(char **line_comb)
{
	char		*str; 
	t_buffer	*buffer;
	t_buffer	*new_buffer;

	buffer = NULL;
	str = NULL;
	buffer = malloc(sizeof(t_buffer));
	//buffer->content = malloc(2000);
	new_buffer = stringbuffer_create_node(&buffer);
	while (**line_comb)
	{
		if (**line_comb == '\'') //hier auch absichern && line_comb[0][0] != '\0' &&  line_comb[0] != NULL
			read_single_quoted(line_comb, &buffer);
		else if (**line_comb == '"') 
			read_double_quoted(line_comb, &buffer);
        // else if (line_comb[0][0] == '$') // hier auf NULL abasichern von linecomb und linecomb[0] und linecomb[0][0]
        // // {
        // //     char *value = get_value(read_varname(line_comb)); 
        // //     stringbuffer_append_string(buffer, value);
        // // }
		else if (is_breaking_char(line_comb) == 1) // | whitespaces redirections (evtl Klammern)
			break ;
		else
		{
			// // printf("| %s |\n", buffer->content);
			stringbuffer_append_char(&buffer, **line_comb);
			(*line_comb)++;
		}
	}
	stringbuffer_get_string(&buffer, &str);
	stringbuffer_destroy(&buffer);
	return (str);
}

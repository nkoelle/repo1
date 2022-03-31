/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_char_to_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolle <nkolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 16:04:06 by nkolle            #+#    #+#             */
/*   Updated: 2022/03/31 14:48:45 by nkolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	add_char_to_buf_list(t_buffer **buffer, char c)
{
	char	*buf_str;
	int		i;

	i = 0;
	buf_str = NULL;
	buf_str = malloc(sizeof(char) * 2);
	buf_str[i] = c;
	buf_str[i + 1] = '\0';
	(*buffer)->content = ft_strjoin_free((*buffer)->content, buf_str);
	if (buf_str)
		free (buf_str);
	buf_str = NULL;
}

void	add_str_to_buf_list(t_buffer **buffer, char *s)
{
	t_buffer	*new_buffer;

	new_buffer = NULL;
	new_buffer = add_new_elem_to_buffer(buffer);
	new_buffer->content = ft_strdup(s);
	if (s)
		free(s);
	s = NULL;
}

// void	add_str_to_op_list(t_operator **operator,enum e_operator redir_type, char c)
// {
	
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_id_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolle <nkolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 15:37:38 by nkolle            #+#    #+#             */
/*   Updated: 2022/03/30 15:37:04 by nkolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h" 
// nochmal scahuen wegen check int prototype wenn !newstr dann break oä in read_iden
int stringbuffer_append_char(t_buffer **buffer, char c)
{
	char *newstr;
	int count;

	newstr = malloc(ft_strlen((*buffer)->content) + 2);
	if (!newstr)
		return (0);
	count = 0;
	while ((*buffer)->content != NULL && (*buffer)->content[count])
	{
		newstr[count] = (*buffer)->content[count];
		count++;
	}
	newstr[count] = c;
	newstr[count + 1] = '\0';
	if ((*buffer)->content != NULL)
		free((*buffer)->content);
	(*buffer)->content = newstr;
	return (1);
}

t_buffer	*stringbuffer_create_node(t_buffer **buffer)
{
	t_buffer	*new_element_buf;

	(void)buffer;
	new_element_buf = malloc(sizeof(t_buffer));
	if (!new_element_buf)
		return (NULL);
	new_element_buf->content = NULL;
	new_element_buf->next = NULL;
	return (new_element_buf);
}

void	stringbuffer_destroy(t_buffer **buffer)
{
	free(*buffer);
	(*buffer) = NULL;
}

void	stringbuffer_get_string(t_buffer **buffer, char **str)
{
	*str = ft_strdup((*buffer)->content);
}

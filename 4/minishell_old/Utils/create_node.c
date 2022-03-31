/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolle <nkolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 15:10:03 by nkolle            #+#    #+#             */
/*   Updated: 2022/03/30 15:40:34 by nkolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_buffer	*new_element(char *content)
{
	t_buffer	*new_element;

	new_element = malloc(sizeof(t_buffer));
	if (new_element != NULL)
	{
		new_element->content = content;
		new_element->next = NULL;
	}
	return (new_element);
}

void	append_string_to_linked_list(t_buffer **buffer, char *content)
{
	t_buffer	*new_buffer;

	new_buffer = new_element(content);
	// (*buffer)->next = new_buffer;
	// else
	ft_lstadd_back_buf(buffer, new_buffer);
}

t_operator	*new_element_op(char *content, enum e_operator type)
{
	t_operator	*new_element;

	new_element = malloc(sizeof(t_operator));
	if (new_element != NULL)
	{
		new_element->content = content;
		new_element->redir_type = type;
		new_element->next = NULL;
	}
	return (new_element);
}

void	append_string_to_redirection_list(t_operator **operator, enum e_operator type, char *content)
{
	t_operator	*new_op;

	new_op = new_element_op(content, type);
	// if (operator->next == NULL)
	// 	(*operator)->next = new_op;
	// else
	ft_lstadd_back_op(operator, new_op);
}

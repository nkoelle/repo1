/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolle <nkolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 15:10:03 by nkolle            #+#    #+#             */
/*   Updated: 2022/03/04 16:00:47 by nkolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_argv_list	*new_element(char *content)
{
	t_argv_list	*new_element;

	new_element = malloc(sizeof(t_argv_list));
	if (!new_element)
		return (NULL);
	new_element->content = ft_strdup(content);
	new_element->next = NULL;
	return (new_element);
}

void	assign_element(t_input **head, char *content)
{
	t_input	*new_elem;

	new_elem = new_element(content);
	new_elem->next = *head;
	*head = new_elem;
}
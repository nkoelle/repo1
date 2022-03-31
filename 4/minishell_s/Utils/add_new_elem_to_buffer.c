/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_new_elem_to_buffer.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolle <nkolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 19:48:30 by nkolle            #+#    #+#             */
/*   Updated: 2022/03/30 20:19:03 by nkolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_buffer	*add_new_elem_to_buffer(t_buffer **buffer)
{
	t_buffer	*new_ele;
	t_buffer	*tmp;

	tmp = (*buffer); 
	new_ele = malloc(sizeof(t_buffer));
	if (!new_ele)
		return(NULL);
	new_ele->content = NULL;
	if ((*buffer))
	{
		new_ele->next = NULL;
		(*buffer)->next = new_ele;
	}
	else
		new_ele->next = NULL;
	return (new_ele);
}

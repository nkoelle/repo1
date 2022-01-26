/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_rra.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolle <nkolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 18:41:45 by nkolle            #+#    #+#             */
/*   Updated: 2022/01/21 13:33:54 by nkolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Push_swap.h"

void	rev_rotate_rra(t_stack **head)
{
	t_stack *tmp;
	t_stack *tmp2;
	
	tmp = *head;
	tmp2 = tmp;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	*head = tmp->next;
	(*head)->next = tmp2;
	tmp->next = NULL;

	write(1, "rra\n", 4);
}
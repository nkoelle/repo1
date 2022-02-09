/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_rrb.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolle <nkolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 17:05:07 by nkolle            #+#    #+#             */
/*   Updated: 2022/02/08 16:26:54 by nkolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Push_swap.h"

void	rev_rotate_rrb(t_stack **head)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp = *head;
	tmp2 = tmp;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	*head = tmp->next;
	(*head)->next = tmp2;
	tmp->next = NULL;
	write(1, "rrb\n", 4);
}

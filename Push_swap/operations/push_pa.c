/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_pa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolle <nkolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 18:41:36 by nkolle            #+#    #+#             */
/*   Updated: 2022/02/08 16:26:26 by nkolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Push_swap.h"

void	push_pa(t_stack **head_a, t_stack **head_b)
{
	t_stack	*tmp;

	tmp = NULL;
	if (!head_b)
	{
		(*head_b) = (*head_a);
		(*head_a) = (*head_a)->next;
		(*head_b)->next = NULL;
	}
	if (*head_b)
	{
		tmp = (*head_b)->next;
		(*head_b)->next = *head_a;
		*head_a = *head_b;
		*head_b = tmp;
	}
	write(1, "pa\n", 3);
}

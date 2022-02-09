/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_pb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolle <nkolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 16:58:07 by nkolle            #+#    #+#             */
/*   Updated: 2022/02/08 16:26:29 by nkolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Push_swap.h"

void	push_pb(t_stack **head_a, t_stack **head_b)
{
	t_stack	*tmp;

	tmp = NULL;
	if (!head_a || !head_b)
		return ;
	if (*head_a)
	{
		tmp = (*head_a)->next;
		(*head_a)->next = (*head_b);
		(*head_b) = *head_a;
		(*head_a) = tmp;
	}
	write(1, "pb\n", 3);
}

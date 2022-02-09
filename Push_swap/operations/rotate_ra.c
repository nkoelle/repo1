/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_ra.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolle <nkolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 18:41:48 by nkolle            #+#    #+#             */
/*   Updated: 2022/02/08 16:27:15 by nkolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Push_swap.h"

void	rotate_ra(t_stack **head)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp = (*head);
	(*head) = (*head)->next;
	tmp2 = (*head);
	while (tmp2->next != NULL)
		tmp2 = tmp2->next;
	tmp2->next = tmp;
	tmp->next = NULL;
	write(1, "ra\n", 3);
}

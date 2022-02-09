/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_rb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolle <nkolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 17:02:34 by nkolle            #+#    #+#             */
/*   Updated: 2022/02/08 16:27:24 by nkolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Push_swap.h"

void	rotate_rb(t_stack **head)
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
	write(1, "rb\n", 3);
}

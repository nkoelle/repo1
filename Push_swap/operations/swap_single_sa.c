/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_single_sa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolle <nkolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 18:41:53 by nkolle            #+#    #+#             */
/*   Updated: 2022/02/08 16:27:36 by nkolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Push_swap.h"

void	swap_single_sa(t_stack **head)
{
	t_stack	*tmp;

	tmp = (*head)->next;
	(*head)->next = tmp->next;
	tmp->next = (*head);
	(*head) = tmp;
	write(1, "sa\n", 3);
}

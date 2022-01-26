/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_both_rr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolle <nkolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 18:41:50 by nkolle            #+#    #+#             */
/*   Updated: 2022/01/21 13:32:24 by nkolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Push_swap.h"

void	rotate_both_rr(t_stack **head_a, t_stack **head_b)
{
	if (head_a && head_b)
	{
		rotate_ra(head_a);
		rotate_ra(head_b);
	}
	else
		return ;
}
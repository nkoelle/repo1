/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_both_rrr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolle <nkolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 18:41:39 by nkolle            #+#    #+#             */
/*   Updated: 2022/01/21 13:28:38 by nkolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Push_swap.h"

void	rev_rotate_both_rrr(t_stack **head_a, t_stack **head_b)
{
	if (head_a && head_b)
	{
		rev_rotate_rra(head_a);
		rev_rotate_rra(head_b);
	}
	else
		return ;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_both_ss.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolle <nkolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 18:44:33 by nkolle            #+#    #+#             */
/*   Updated: 2022/02/08 16:27:32 by nkolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Push_swap.h"

void	swap_both_ss(t_stack **head_a, t_stack **head_b)
{
	if (head_a && head_b)
	{
		swap_single_sa(head_a);
		swap_single_sa(head_b);
	}
	write(1, "ss\n", 3);
}

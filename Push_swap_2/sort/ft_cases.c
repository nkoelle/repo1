/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cases.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolle <nkolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 18:57:39 by nkolle            #+#    #+#             */
/*   Updated: 2022/01/28 16:09:33 by nkolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Push_swap.h"

void	case_one(t_stack **stack_a)
{
	swap_single_sa(stack_a);
}

void	case_two(t_stack **stack_a)
{
	swap_single_sa(stack_a);
	rev_rotate_rra(stack_a);
}

void	case_three(t_stack **stack_a)
{
	rotate_ra(stack_a);
}

void	case_four(t_stack **stack_a)
{
	swap_single_sa(stack_a);
	rotate_ra(stack_a);
}

void	case_five(t_stack **stack_a)
{
	rev_rotate_rra(stack_a);
}

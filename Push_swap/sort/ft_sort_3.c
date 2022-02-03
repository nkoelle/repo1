/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolle <nkolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 18:42:29 by nkolle            #+#    #+#             */
/*   Updated: 2022/02/03 17:37:17 by nkolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Push_swap.h"

void	ft_sort_3(t_stack **stack_a, int argc)
{
	int	a;
	int	b;
	int	c;

	if (argc == 3)
		return (ft_sort_2(stack_a, argc));
	a = (*stack_a)->content;
	b = (*stack_a)->next->content;
	c = (*stack_a)->next->next->content;
	if (a > b && b < c && c > a)
	{
		case_one(stack_a);
		return ;
	}
	if (a > b && b > c && c < a)
	{
		case_two(stack_a);
		return ;
	}
	if (a > b && a > c && c > b)
	{
		case_three(stack_a);
		return ;
	}
	if (a < b && a < c && b > c)
	{
		case_four(stack_a);
		return ;
	}
	if (a < b && a > c && b > c)
	{
		case_five(stack_a);
		return ;
	}
}

void	ft_sort_2(t_stack **stack_a,int argc)
{
	int	a;
	int	b;

	a = (*stack_a)->content;
	b = (*stack_a)->next->content;
	if (argc == 0)
		return ;
	if (argc > 0)
	{
		if (a < b)
			return ;
		if (a > b)
			swap_single_sa(stack_a);
	}
	return ;
}

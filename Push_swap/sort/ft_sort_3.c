/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolle <nkolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 18:42:29 by nkolle            #+#    #+#             */
/*   Updated: 2022/02/08 16:57:21 by nkolle           ###   ########.fr       */
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
		return (case_one(stack_a));
	if (a > b && b > c && c < a)
		return (case_two(stack_a));
	if (a > b && a > c && c > b)
		return (case_three(stack_a));
	if (a < b && a < c && b > c)
		return (case_four(stack_a));
	if (a < b && a > c && b > c)
		return (case_five(stack_a));
}

void	ft_sort_2(t_stack **stack_a, int argc)
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

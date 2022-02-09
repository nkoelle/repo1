/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolle <nkolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 18:42:45 by nkolle            #+#    #+#             */
/*   Updated: 2022/02/08 17:26:19 by nkolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Push_swap.h"

void	ft_sort_5(t_stack **stack_a, t_stack **stack_b, int argc)
{
	find_min(stack_a, stack_b);
	if (argc == 6)
		find_min(stack_a, stack_b);
	ft_sort_3(stack_a, argc);
	push_pa(stack_a, stack_b);
	push_pa(stack_a, stack_b);
}

//rotating minimum_node in stack_a to top position in stack_a 
//to push it in right order to stack_b
//in order to have only 3 numbers in stack_a ->ft_sort_3
void	find_min(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int		min_pos;
	int		count;

	count = 0;
	tmp = (*stack_a);
	min_pos = search_min(&tmp);
	while (min_pos <= 3 && min_pos > 1)
	{
		rotate_ra(stack_a);
		min_pos--;
	}
	while (min_pos <= 5 && min_pos > 3)
	{
		if (ft_lstsize(*stack_a) == 4 && min_pos == 5)
			break ;
		rev_rotate_rra(stack_a);
		min_pos++;
	}
	 push_pb(stack_a, stack_b);
}

//getting the position of the minmum number in stack_a 
//and returnig it to find_min
int	search_min(t_stack **tmp)
{
	int	min_pos;
	int	min;
	int	count;

	min = (*tmp)->content;
	min_pos = 0;
	count = min_pos;
	while ((*tmp))
	{
		count++;
		if ((*tmp)->content < min)
		{
			min_pos = count;
			min = (*tmp)->content;
		}
		(*tmp) = (*tmp)->next;
	}
	return (min_pos);
}

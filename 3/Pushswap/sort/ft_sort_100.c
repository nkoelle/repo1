/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_100.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolle <nkolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 19:05:16 by nkolle            #+#    #+#             */
/*   Updated: 2022/02/15 16:23:09 by nkolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Push_swap.h"
// comparing two contents in stack a and giving them an index on their 
// value-difference
void	ft_index(t_stack **stack_a)
{
	t_stack	*temp;
	t_stack	*head;
	int		counter;

	head = *stack_a;
	temp = *stack_a;
	while (temp)
	{
		head = *stack_a;
		counter = 1;
		temp->index = 1;
		while (head)
		{
			if (head->content < temp->content)
			{
				counter++;
				temp->index = counter;
			}
			head = head->next;
		}
		temp = temp->next;
	}
}

// determine the max bit length through bit shifting and returning it
int	ft_bits(t_stack **stack_a)
{
	t_stack	*head;
	int		max;
	int		bit_length;

	head = *stack_a;
	max = head->index;
	bit_length = 1;
	while (head)
	{
		if (head->index > max)
			max = head->index;
		head = head->next;
	}
	while ((max >> bit_length) != 0)
		bit_length++;
	return (bit_length);
}

// pushing the numbers to b in order of their bits
void	ft_sort_100(t_stack **stack_a, t_stack **stack_b)
{
	int	bits;
	int	i;
	int	j;
	int	size_stack;

	i = 0;
	ft_index(stack_a);
	size_stack = ft_lstsize(*stack_a);
	bits = ft_bits(stack_a);
	while (i < bits)
	{
		j = 0;
		while (j < size_stack)
		{
			if (((*stack_a)->index >> i & 1) == 0)
				push_pb(stack_a, stack_b);
			else
				rotate_ra(stack_a);
			j++;
		}
		while (ft_lstsize(*stack_b) != 0)
			push_pa(stack_a, stack_b);
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolle <nkolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 17:04:43 by nkolle            #+#    #+#             */
/*   Updated: 2022/02/10 12:54:03 by nkolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Push_swap.h"

int	ft_sorted(t_stack **stack_a)
{
	t_stack	*tmp;

	tmp = (*stack_a);
	while (tmp->next != NULL)
	{
		if (tmp->content < tmp->next->content)
			tmp = tmp->next;
		else
			return (0);
	}
	return (1);
}

void	sort_stack(int argc, t_stack **stack_a, t_stack **stack_b)
{
	if (argc == 2 || argc == 3)
		ft_sort_3(stack_a, argc);
	if (argc == 4 || argc == 5)
		ft_sort_5(stack_a, stack_b, argc);
	if (argc > 5)
		ft_sort_100(stack_a, stack_b);
}

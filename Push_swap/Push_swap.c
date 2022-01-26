/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolle <nkolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:07:15 by nkolle            #+#    #+#             */
/*   Updated: 2022/01/26 17:57:11 by nkolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

int	main(int argc, char **argv)
{
	t_stack *stack_a;
	t_stack *stack_b;
	int		i;

	i = argc - 1;
	stack_a = NULL;
	stack_b = NULL;
	if (ft_isint(argv) == 0)
		return (ft_error_message());
	// writing the input *argv[i] into stack_a
	while (i > 0)
	{
		push_element(&stack_a, ft_atoi(argv[i]));
		if (ft_dupnumb(stack_a, ft_atoi(argv[i])) == 1)
			return (ft_error_message());
		i--;
	}
	
	print_stack(&stack_a);
	return (0);
}

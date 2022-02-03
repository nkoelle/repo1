/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolle <nkolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:07:15 by nkolle            #+#    #+#             */
/*   Updated: 2022/02/03 18:27:38 by nkolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

int	main(int argc, char **argv)
{
	t_stack *stack_a;
	t_stack *stack_b;
	int		i;
	int		error;

	error = 0;
	i = argc - 1;
	stack_a = NULL;
	stack_b = NULL;
	if (ft_isint(argv) == 0)
		return (ft_error_message());
	// writing the input *argv[i] into stack_a
	while (i > 0)
	{
		if (ft_dupnumb(stack_a, ft_atoi(argv[i], &error)) == 1)
			return (ft_error_message());
		push_element(&stack_a, ft_atoi(argv[i], &error));
		i--;
		if (error == 1)
			return(ft_error_message());
	}
	if (argc == 3 || argc == 4)
		ft_sort_3(&stack_a, argc);
	if (argc == 5 || argc == 6)
		ft_sort_5(&stack_a, &stack_b, argc);
	// if (argc > 5)
	// 	ft_sort_100(stack_a);
	print_stack(stack_a);
	return (0);
}

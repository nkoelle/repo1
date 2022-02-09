/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolle <nkolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:07:15 by nkolle            #+#    #+#             */
/*   Updated: 2022/02/09 15:02:11 by nkolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"
// convert string into an int using atoi and split to exclude spaces
int	convert_string(t_stack **stack_a, char **argv, int argc)
{
	int		error;
	int		i;
	int		t;
	char	**s;

	i = argc - 1;
	while (i > 0)
	{
		t = 0;
		s = ft_split(argv[i], ' ');
		while (s[t])
		{
			if (ft_dupnumb(*stack_a, ft_atoi(s[t], &error)) == 1)
				return (1);
			push_element(stack_a, ft_atoi(s[t], &error));
			if (error == 1)
				return (1);
			t++;
		}
		i--;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		error;

	error = 0;
	stack_a = NULL;
	stack_b = NULL;
	if (ft_isint(argv) == 1 || argc == 1)
		return (ft_error_message());
	if (convert_string(&stack_a, argv, argc) == 1)
		return (ft_error_message());
	if (ft_sorted(&stack_a) == 1)
		return (0);
	if (argc == 3 || argc == 4)
		ft_sort_3(&stack_a, argc);
	if (argc == 5 || argc == 6)
		ft_sort_5(&stack_a, &stack_b, argc);
	if (argc > 6)
		ft_sort_100(&stack_a, &stack_b);
	print_stack(stack_a);
	return (0);
}

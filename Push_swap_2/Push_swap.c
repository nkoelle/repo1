/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolle <nkolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:07:15 by nkolle            #+#    #+#             */
/*   Updated: 2022/02/10 14:45:20 by nkolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

//checking wether str has input
int	is_null_str(char *str)
{
	while (*str)
	{
		if (*str != ' ')
			return (0);
		str++;
	}
	return (1);
}

int	is_null_args(char *argv[])
{
	argv++;
	while (*argv)
	{
		if (!is_null_str(*argv))
			return (0);
		argv++;
	}
	return (1);
}

// convert string into an int using atoi and split to exclude spaces
int	convert_string(t_stack **stack_a, char **argv, int argc, int *error)
{
	int		i;
	int		t;
	char	**s;

	i = argc - 1;
	while (i > 0)
	{
		if (!is_null_str(argv[i]))
		{
			s = ft_split(argv[i], ' ');
			t = 0;
			while (s[t])
				t++;
			t -= 1;
			while (t >= 0)
			{
				if (push_string(stack_a, s, error, t) == 0)
					t--;
				else
					return (1);
			}
		}
		i--;
	}
	return (0);
}

// pushig the elements to stack_a
int	push_string(t_stack **stack_a, char **s, int *error, int t)
{
	if (ft_dupnumb(*stack_a, ft_atoi(s[t], error)) == 0)
		push_element(stack_a, ft_atoi(s[t], error));
	else
		return (1);
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
	if (argc == 1)
		return (0);
	if (is_null_args(argv))
		return (1);
	if (convert_string(&stack_a, argv, argc, &error) == 1)
		return (ft_error_message());
	argc = ft_lstsize(stack_a);
	if (ft_sorted(&stack_a))
		return (0);
	if (error == 3)
		return (0);
	if (error == 1)
		return (ft_error_message());
	sort_stack(argc, &stack_a, &stack_b);
	exit (0);
	return (0);
}

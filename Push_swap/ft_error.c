/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolle <nkolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 16:17:41 by nkolle            #+#    #+#             */
/*   Updated: 2022/02/09 15:02:42 by nkolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

//input check of strings argv[i++] and their elements j
int	ft_isint(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		if (ft_strlen(argv[i]) == 10 && argv[i][j] != '-')
			return (ft_sizeofint(argv[i]));
		if (ft_strlen(argv[i]) == 11 && argv[i][j] == '-')
			return (ft_sizeofint(argv[i]));
		if (ft_strlen(argv[i]) > 10)
			return (0);
		i++;
	}
	return (1);
}

// check wether number has in value
// -2,147,483,648 to 2,147,483,647
int	ft_sizeofint(char *s)
{
	char	*s1;
	char	*s2;
	int		i;

	i = 0;
	s1 = "-2147483648";
	s2 = "2147483647";
	while (s[i])
	{
		if (s[i] == '-')
			return (min_min(s, s1, &i));
		if (s[i] <= s2[i])
			i++;
		else
			return (0);
	}
	return (1);
}

// check wether number is an actual number
int	ft_only_num(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		if ((argv[i][j] == '-' || argv[i][j] == '+')
			&& ft_isdigit(argv[i][++j]) != 0)
			j++;
		if (((argv[i][j] >= '0' && argv[i][j] <= '9')
			 && ft_isdigit(argv[i][j]) != 0) || argv[i][j] == ' ')
			j++;
		else
			return (0);
	}
	return (1);
}

// check wether number is duplicated
int	ft_dupnumb(t_stack *stack_a, int c)
{
	t_stack	*tmp;

	tmp = stack_a;
	while (tmp != NULL)
	{
		if (tmp->content == c)
			return (1);
		if (tmp->content != c)
			tmp = tmp->next;
	}
	return (0);
}

// handling minus minimal value
int	min_min(char *s, char *s1, int *i)
{
	while (s[*i])
	{
		if (s[*i] <= s1[*i])
			i++;
		else
			return (0);
	}
	return (1);
}

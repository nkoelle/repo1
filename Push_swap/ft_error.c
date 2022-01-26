/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolle <nkolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 16:17:41 by nkolle            #+#    #+#             */
/*   Updated: 2022/01/26 17:54:33 by nkolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

//input check von den strings argv[i++] und deren elemente j
int	ft_isint(char **argv)
{
	int		i;
	int		j;

	i = 1;
	while (argv[i])
	{
		//printf("1 i = %d argv = %s \n", i ,argv[i]);
		j = 0;
		if (ft_strlen(argv[i]) == 10 && argv[i][j] != '-')
			return(ft_sizeofint(argv[i]));
		if (ft_strlen(argv[i]) == 11 && argv[i][j] == '-')
			return(ft_sizeofint(argv[i]));
		if (ft_strlen(argv[i]) > 10)
			return (0);
		if ((argv[i][j] == '-' || argv[i][j] == '+' || argv[i][j] == '0') 
			&& ft_isdigit(argv[i][1]) != 0)
			j++;
		if ((argv[i][j] >= '0' && argv[i][j] <= '9') || argv[i][j] == ' ')
			j++;
		//printf("2 i = %d argv = %s \n", i ,argv[i]);	
		i++;
	}
	return (1);
}
// checken ob die zahl int value hat 
// -2,147,483,648 to 2,147,483,647
int	ft_sizeofint(char *s)
{
	char	*s1;
	char	*s2;
	int		i;
	
	i = 0;
	s1 = NULL;
	s2 = NULL;
	s1 = "-2147483648";
	s2 = "2147483647";
	while (s[i])
	{
		if (s[i] == '-')
		{
			while (s[i])
			{
				if (s[i] <= s1[i])
					i++;
				else
					return (0);
			}
			return (1);
		}
		if (s[i] <= s2[i])
			i++;
		else
			return (0);
	}
	return (1);
}

int	ft_dupnumb(t_stack *stack_a, int c)
{
	while (!stack_a)
	{
		if(stack_a->content == c)
			return(1);
		stack_a = stack_a->next;
	}
	return (0);
}
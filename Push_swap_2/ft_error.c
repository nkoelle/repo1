/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolle <nkolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 16:17:41 by nkolle            #+#    #+#             */
/*   Updated: 2022/02/10 12:09:08 by nkolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

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

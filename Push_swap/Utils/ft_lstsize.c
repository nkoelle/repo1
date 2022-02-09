/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolle <nkolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 17:09:18 by nkolle            #+#    #+#             */
/*   Updated: 2022/02/07 16:10:04 by nkolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Push_swap.h"

int	ft_lstsize(t_stack *lst)
{
	int		i;
	t_stack	*element;

	i = 0;
	element = lst;
	while (element != NULL)
	{
		element = element->next;
		i++;
	}
	return (i);
}

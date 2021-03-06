/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolle <nkolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 14:10:12 by nkolle            #+#    #+#             */
/*   Updated: 2022/02/08 16:21:56 by nkolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Push_swap.h"

t_stack	*new_stack(int content)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

void	push_element(t_stack **head, int content)
{
	t_stack	*new_elem;

	new_elem = new_stack(content);
	new_elem->next = *head;
	*head = new_elem;
}

void	print_stack(t_stack *head)
{
	t_stack	*tmp;

	tmp = head;
	while (tmp)
	{
		printf("%d\n", tmp->content);
		tmp = tmp->next;
	}
}

int	ft_error_message(void)
{
	printf("Error\n");
	return (1);
}

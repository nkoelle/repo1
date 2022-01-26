/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolle <nkolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:07:33 by nkolle            #+#    #+#             */
/*   Updated: 2022/01/26 17:54:28 by nkolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct s_stack 
{
	int content;
	struct s_stack *next;
}	t_stack;

int		main(int argc, char **argv);

// ft_error managament
int		ft_isint(char **argv);
int		ft_sizeofint(char *s);
int		ft_dupnumb(t_stack *stack_a, int c);

// Utils = helperfunctions for allocating or other stuff
t_stack *new_stack(int content);
t_stack	*ft_lstlast_ps(t_stack *lst);
void	print_stack(t_stack **head);
int		ft_error_message(void);
int		ft_atoi(const char *str);
void	push_element(t_stack **head, int content);
void	ft_lstadd_front(t_stack **lst, t_stack *new);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);
int		ft_isdigit(int c);

//Operations
void	rotate_ra(t_stack **stack);
void	rev_rotate_rra(t_stack **head);
void	rotate_both_rr(t_stack **head_a, t_stack **head_b);
void	rev_rotate_both_rrr(t_stack **head_a, t_stack **head_b);
void	push_pa(t_stack **head_a, t_stack **head_b);
void	swap_both_ss(t_stack **head_a, t_stack **head_b);
void	swap_single_sa(t_stack **head);


#endif
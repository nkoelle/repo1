/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolle <nkolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:04:21 by nkolle            #+#    #+#             */
/*   Updated: 2022/03/30 15:13:54 by nkolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../minishell"

// void	append_string_to_linked_list(t_buffer **buffer, char *content)
// {
// 	t_buffer	*new_buffer;

// 	if ((*buffer)->next != NULL)
// 		new_buffer = new_element(content);
// 	new_buffer = ft_lstlast_buf(new_buffer);
// }

// t_operator	*new_element_op(char *content)
// {
// 	t_operator	*new_element;

// 	new_element = malloc(sizeof(t_operator));
// 	if (!new_element)
// 		return (NULL);
// 	new_element->content = ft_strdup(content);
// 	new_element->next = NULL;
// 	return (new_element);
// }

// void	append_string_to_redirection_list
// 		(t_operator *operator, enum e_operator redir_type, char *content)
// {
// //wie übergeben wir enum und joinen enum und line_comb(str)

// 	content = ft_strjoin_free(redir_type, content);//free in strjoin? -> hab ich umgeschrieben in sjoin nicht getestet! checken wegen enumvalue
// 	new_operator = new_element_op(content);
// 	new_operator = ft_lstlast_op(new_operator);
// }
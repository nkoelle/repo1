/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolle <nkolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 16:52:51 by nkolle            #+#    #+#             */
/*   Updated: 2022/03/30 15:43:54 by nkolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	save_line(void)
{
	char		*line;
	t_buffer	*buffer;
	t_operator	*operator;
	t_input		*input;

	input = NULL;
	line = NULL;
	buffer = NULL;
	operator = NULL;
	buffer = malloc(sizeof(t_buffer));
	input = malloc(sizeof(t_input));
	operator = malloc(sizeof(t_operator));
	line = readline("$");
	parser(line, &input, &buffer, &operator);
}

int	main(void)
{
	save_line();

	return(0);
}


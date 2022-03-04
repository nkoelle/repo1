/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolle <nkolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 16:52:51 by nkolle            #+#    #+#             */
/*   Updated: 2022/03/04 16:08:23 by nkolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

//case 1 Operators(< |)  : between two spaces,tabs or words, or one of them.

//case 2 words (strings) : starting with i = 0 || i - 1 = space oder tab
//							ending with line[i] == ' ' || line[i] == (int)9 || line[i] == '\0'
//case 3 space, tab (' ' || (int)9) : after words, operators, tabs, spaces
//case 4 quotes (" ")	: string to save, not to change, printing error if only 1 quote
// void	checktype(t_input *input, char *word)
// {
//		check type
// }
void	save_line(void)
{
	char		*line;
	t_argv_list	*element;
	char		*line_comb;
	int			i;

	i = 0;
	line = NULL;
	element = NULL;
	malloc(sizeof(t_argv_list));
	line = readline("$");
	parser(line, element);

	//parser(line_comb);
}

int	main(void)
{
	save_line();

	return(0);
}

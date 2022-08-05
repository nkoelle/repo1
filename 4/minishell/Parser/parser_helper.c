/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolle <nkolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 21:35:28 by nkolle            #+#    #+#             */
/*   Updated: 2022/08/04 21:43:25 by nkolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	parser_helper(char	**line_comb, t_operator **operator, int *pos)
{
	if (check_for_str(*line_comb, "<<"))
		fck_norm1(line_comb, operator, pos);
	else if (check_for_str(*line_comb, ">>"))
		fck_norm2(line_comb, operator, pos);
	else if (check_for_str(*line_comb, "<"))
		fck_norm3(line_comb, operator, pos);
	else if (check_for_str(*line_comb, ">"))
		fck_norm4(line_comb, operator, pos);
}

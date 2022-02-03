
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolle <nkolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 17:25:13 by nkolle            #+#    #+#             */
/*   Updated: 2022/01/19 18:51:29 by nkolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Push_swap.h"

int	ft_atoi(const char *str, int *error)
{
	int	i;
	int	sign;
	int	strvalue;
	int	signcounter;

	sign = 1;
	strvalue = 0;
	signcounter = 0;
	i = 0;
	while (str[i] == (int)32 || str[i] == (int)9 || str[i] == (int)11
		|| str[i] == '\f' || str[i] == '\r' || str[i] == '\n')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		signcounter++;
		i++;
	}
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			strvalue = strvalue * 10 + str[i] - '0';
		else
			*error = 1;
		i++;
	}
	if (signcounter > 1)
		*error = 1;
	return (strvalue * sign);
}

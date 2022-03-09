/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolle <nkolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 17:25:13 by nkolle            #+#    #+#             */
/*   Updated: 2022/02/09 15:14:28 by nkolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Push_swap.h"

long	ft_atoi2(const char *str, int *error, int i, long strvalue)
{
	while (str[i])
	{
		if (str[i] == (int)34)
			i++;
		if (str[i] >= '0' && str[i] <= '9')
			strvalue = strvalue * 10 + str[i] - '0';
		else
			*error = 1;
		i++;
	}
	return (strvalue);
}

long	ft_atoi(const char *str, int *error)
{
	int		i;
	long	sign;
	long	strvalue;
	int		signcounter;

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
	strvalue = ft_atoi2(str, error, i, strvalue);
	if (signcounter > 1 || strvalue * sign > INT_MAX
		|| strvalue * sign < INT_MIN)
		*error = 1;
	return (strvalue * sign);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolle <nkolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 17:25:13 by nkolle            #+#    #+#             */
/*   Updated: 2022/02/14 16:36:12 by nkolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	strvalue;

	sign = 1;
	strvalue = 0;
	i = 0;
	while (str[i] == (int)32 || str[i] == (int)9 || str[i] == (int)11
		|| str[i] == '\f' || str[i] == '\r' || str[i] == '\n')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		{
			sign = -1;
		}
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		strvalue = strvalue * 10 + str[i] - '0';
		i++;
	}
	return (strvalue * sign);
}

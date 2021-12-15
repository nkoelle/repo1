/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolle <nkolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 15:44:30 by nkolle            #+#    #+#             */
/*   Updated: 2021/12/14 15:48:34 by nkolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	check(char *str, char c, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	int	i;
	int	j;

	if (ac == 3)
	{
		i = 0;
		while (av[1][i])
		{
			if (check(av[1], av[1][i], i) == 0)
			{
				j = 0;
				while (av[2][j])
				{
					if (av[2][j] == av[1][i])
					{
						ft_putchar(av[1][i]);
						break ;
					}
					j++;
				}
			}
			i++;
		}
	}
	ft_putchar('\n');
	return (0);
}

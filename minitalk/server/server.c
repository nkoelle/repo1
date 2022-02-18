/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolle <nkolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 16:39:23 by nkolle            #+#    #+#             */
/*   Updated: 2022/02/18 13:45:49 by nkolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minitalk.h"

// verarbeitet SIGUSR1 indem er die Client_bits in int umwandelt, und
// dann in Str mit atoi || SIGUSR2 => error
void	signal_handler(int client_bits)
{
	static char	buf[8];
	char	c;
	int		i;

	i = 0;
	if (SIGUSR1)
	{
		while (i < 8)
		{
			buf[i] = client_bits;
			printf("buf = %s \n", buf);
			i++;
		}
		buf[i] = '\0';
	}
	printf("NOT HERE!\n");
	c = convert_str(buf);
	write (1, &c, 1);
	if (SIGUSR2)
		exit(0);
}

char	convert_str(char buf[8])
{
	int	i;
	int result;
	int counter;

	counter = 0;
	result = 0;
	printf("buf = %s \n", buf);
	i = 7;
	while(i > -1)
	{
		if (buf[i] == 1)
		{
			result += (2 ^ counter);
			printf("c = %d \n", result);
		}
		counter++;
		i--;
	}
	//write (1, &result, 1);
	return ((char)result);
}

int	main(void)
{
	pid_t	server_id;
	
	server_id = getpid();
	ft_putnbr_fd(server_id, 1);
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
		pause();
	return (0);
}

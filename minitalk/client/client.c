/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolle <nkolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 16:39:55 by nkolle            #+#    #+#             */
/*   Updated: 2022/02/16 17:52:58 by nkolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minitalk.h"
void	send_char(char c, pid_t server_id)
{
	int	bits;

	bits = 7;
	while (bits > -1)
	{
		if (c & (1 << bits))
			kill(server_id, SIGUSR1);
		else
			kill(server_id, SIGUSR2);
		bits--;
		usleep(100);
	}
}

void	send_str(char *s, pid_t server_id)
{
	int	i;

	i = 0;
	while(s[i])
	{
		send_char(s[i], server_id);
		i++;
	}
	send_char('\0', server_id);
}

int	main(int argc, char **argv)
{
	pid_t	server_id;
	
	if (argc == 3)
	{
		server_id = ft_atoi(argv[1]);
		send_str(argv[2], server_id);
	}
	return (0);
}

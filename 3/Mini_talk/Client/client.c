/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolle <nkolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 16:39:55 by nkolle            #+#    #+#             */
/*   Updated: 2022/02/18 20:06:38 by nkolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"
// sendet bits der Bitsequenz des erhaltenen Chars durch Kill an den Server
// 1 wird durch den & Operator erkannt und gesendet
// wenn nicht 1 dann wird 0 gesendet

void	send_char(char c, pid_t server_id)
{
	int	bits;
	int	n;

	bits = 7;
	n = 1;
	while (n <= 128)
	{
		if (c & n)
			kill(server_id, SIGUSR1);
		else
			kill(server_id, SIGUSR2);
		n *= 2;
		usleep(100);
	}
}
// sendet char für char des input strings an send_char

void	send_str(char *s, pid_t server_id)
{
	int	i;

	i = 0;
	while (s[i])
	{
		send_char(s[i], server_id);
		i++;
	}
	send_char('\0', server_id);
}
// bekommt als input die server id und den string der gesendet werden soll

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

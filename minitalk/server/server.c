/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolle <nkolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 16:39:23 by nkolle            #+#    #+#             */
/*   Updated: 2022/02/18 20:10:45 by nkolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

// verarbeitet SIGUSR1 indem er die Client_bits bit für bit vergleicht.
// wenn 1 dann wird result um counter erhöht bei 0 nur der counter
// weil static müssen res und counter neu intitalisiert werden.

void	signal_handler(int client_bits)
{
	static int	result = 0;
	static int	counter = 1;

	if (SIGUSR1 == client_bits)
			result += counter;
	counter *= 2;
	if (counter == 256)
	{
		write (1, &result, 1);
		result = 0;
		counter = 1;
	}
}
// signal erkennt durch SIGUSR1 || SIGUSR2 ob Signal 1 oder 0 ist
// übergibt das Signal dann an den sighandler

int	main(void)
{
	pid_t	server_id;

	server_id = getpid();
	ft_putnbr_fd(server_id, 1);
	while (1)
	{
		signal(SIGUSR1, signal_handler);
		signal(SIGUSR2, signal_handler);
		pause();
	}
	return (0);
}

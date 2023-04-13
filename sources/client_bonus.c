/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goda-sil <goda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 17:53:22 by goda-sil          #+#    #+#             */
/*   Updated: 2023/04/13 18:45:11 by goda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalkbonus.h"

void	delivery(int pid, char message)
{
	int	bit;

	bit = 0;
	while (bit <= 7)
	{
		if ((message >> bit) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(200);
		bit++;
	}
}

void	check_delivery(int signal)
{
	if (signal == SIGUSR2)
		ft_printf("Server received message.\n");
	exit(0);
}

int	main(int argc, char **argv)
{
	int					counter;
	int					pid;
	char				*message;
	struct sigaction	tool;

	tool.sa_handler = &check_delivery;
	counter = 0;
	sigaction(SIGUSR2, &tool, NULL);
	if (check_arguments(argc, argv) != 0)
	{
		pid = ft_atoi(argv[1]);
		message = ft_strdup(argv[2]);
		while (message[counter])
		{
			delivery(pid, message[counter]);
			counter++;
		}
		free(message);
		delivery(pid, '\n');
		delivery(pid, '\0');
	}
	return (0);
}

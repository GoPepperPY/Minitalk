/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goda-sil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:02:03 by goda-sil          #+#    #+#             */
/*   Updated: 2023/04/11 23:18:02 by goda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

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

int	main(int argc, char **argv)
{
	int		counter;
	int		pid;
	char	*message;	

	counter = 0;
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
	}
	return (0);
}

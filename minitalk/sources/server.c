/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goda-sil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:01:54 by goda-sil          #+#    #+#             */
/*   Updated: 2023/04/06 21:23:38 by goda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	print_message(int signal)
{
	static int	bit;
	static int	character;

	if (signal == SIGUSR1)
		character = ((1 << bit) | character);
	if (signal == SIGUSR2)
		character = ((0 << bit) | character);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", character);
		bit = 0;
		character = 0;
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	int		counter;

	(void) argv;
	counter = 0;
	pid = getpid();
	if (argc != 1)
	{
		ft_printf("Verify the input!");
		return (0);
	}
	ft_printf("%d\n", pid);
	signal(SIGUSR1, &print_message);
	signal(SIGUSR2, &print_message);
	while (1)
		pause();
	return (0);
}

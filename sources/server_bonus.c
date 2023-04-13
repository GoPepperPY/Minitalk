/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goda-sil <goda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 17:53:12 by goda-sil          #+#    #+#             */
/*   Updated: 2023/04/13 18:43:27 by goda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalkbonus.h"

void	print_message(int signal, siginfo_t *info, void *ucontext)
{
	static int	bit;
	static int	character;

	(void) ucontext;
	if (signal == SIGUSR1)
		character = ((1 << bit) | character);
	if (signal == SIGUSR2)
		character = ((0 << bit) | character);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", character);
		bit = 0;
		if (character == '\0')
			kill(info->si_pid, SIGUSR2);
		character = 0;
	}
}

int	main(int argc, char **argv)
{
	pid_t				pid;
	struct sigaction	tool;

	(void) argv;
	tool.sa_sigaction = &print_message;
	tool.sa_flags = SA_RESTART | SA_SIGINFO;
	pid = getpid();
	if (argc != 1)
	{
		ft_printf("Verify the input!");
		return (0);
	}
	ft_printf("%d\n", pid);
	sigaction(SIGUSR1, &tool, NULL);
	sigaction(SIGUSR2, &tool, NULL);
	while (1)
		pause();
	return (0);
}

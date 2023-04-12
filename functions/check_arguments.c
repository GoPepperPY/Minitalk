/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goda-sil <goda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 12:33:36 by goda-sil          #+#    #+#             */
/*   Updated: 2023/04/12 20:44:10 by goda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"
#include "../includes/minitalkbonus.h"

int	check_arguments(int argc, char **argv)
{
	int	counter;

	counter = 0;
	if (argc != 3)
	{
		write(1, "verify the input!", 18);
		return (0);
	}
	while (argv[1][counter])
	{
		if (ft_isdigit(argv[1][counter]) == 0)
		{
			write(1, "Pid is a integer!", 18);
			return (0);
		}
		counter++;
	}
	if (!argv[2])
	{
		write(1, "Write a message!", 17);
		return (0);
	}
	return (1);
}

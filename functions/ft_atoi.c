/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goda-sil <goda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:18:10 by goda-sil          #+#    #+#             */
/*   Updated: 2023/04/13 18:44:36 by goda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"
#include "../includes/minitalkbonus.h"

int	ft_atoi(const char *atoa)
{
	int	counter;
	int	saver;
	int	rest;

	rest = 0;
	saver = 1;
	counter = 0;
	while (atoa[counter] == 32 || (atoa[counter] >= 9 && atoa[counter] <= 13))
		counter++;
	if (atoa[counter] == '-')
	{
		saver = -1;
		counter++;
	}
	else if (atoa[counter] == '+')
		counter++;
	while (atoa[counter] >= '0' && atoa[counter] <= '9')
	{
		rest = (atoa[counter] - 48) + (rest * 10);
		counter++;
	}
	return (rest * saver);
}
/*
int	main()
{
	char a[] = "-1231as23";
	char b[] = "-+1231as23";
	char c[] = "+a231as23";
	char d[] = "    21+1231as23";
	char e[] = "     aasdwae";

	printf("\n%d \n", atoi(a));
	printf("%d \n", ft_atoi(a));

	printf("\n%d \n", atoi(b));
	printf("%d \n", ft_atoi(b));

	printf("\n%d\n", atoi(c));
	printf("%d \n", ft_atoi(c));

	printf("\n%d \n", atoi(d));
	printf("%d \n", ft_atoi(d));

	printf("\n%d \n", atoi(e));
	printf("%d \n", ft_atoi(e));

	return(0);
}*/

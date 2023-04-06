/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goda-sil <goda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:41:32 by goda-sil          #+#    #+#             */
/*   Updated: 2023/04/06 21:04:47 by goda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

char	*ft_strdup(char *s)
{
	int		counter;
	int		lenght;
	char	*pointer;

	counter = 0;
	lenght = ft_strlen(s);
	pointer = (char *)malloc((lenght + 1) * sizeof(char));
	if (pointer == NULL)
		return (NULL);
	while (s[counter])
	{
		pointer[counter] = s[counter];
		counter++;
	}
	pointer[counter] = '\0';
	return (pointer);
}
/*
int main()
{
	char a[] = "Teste";
	char *b;

	char c[] = "Teste";
	char *d;

	b = strdup(a);
	d = ft_strdup(c);

	printf("%s \n", b);
	printf("%s \n", d);
}*/

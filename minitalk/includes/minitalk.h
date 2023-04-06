/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goda-sil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:38:07 by goda-sil          #+#    #+#             */
/*   Updated: 2023/04/06 21:22:38 by goda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <sys/types.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <strings.h>
# include <stddef.h>
# include <ctype.h>
# include <stdarg.h>
# include <stdint.h>

void	delivery(int pid, char message);
int		ft_atoi(const char *nptr);
int		ft_isdigit(char c);
char	*ft_strdup(char *s);
int		check_arguments(int argc, char **argv);
int		ft_strlen(char *string);
void	ft_putchar_fd(char c, int fd);
int		ft_printf(const char *input, ...);
int		identify_flag(va_list argument, const char type);
int		print_string(char *string);
int		print_decimal_integer(long number);
int		print_decimal_unsigned(unsigned int number);
int		print_hex(unsigned int number, char type);
int		print_pointer(unsigned long long pointer);
int		print_pointer_two(unsigned long long pointer);
int		pointer_length(unsigned long long pointer);
int		put_hex(unsigned int number, char type);

#endif

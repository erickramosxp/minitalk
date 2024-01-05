/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erramos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 18:52:22 by erramos           #+#    #+#             */
/*   Updated: 2024/01/05 20:09:00 by erramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_string_bit(int pid, char *str)
{
	int	i;
	int	c;

	i = 0;
	while (*str)
	{
		c = *(str);
		while (i < 8)
		{
			if (c << i & 0b10000000)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			i++;
			usleep(500);
		}
		str++;
		i = 0;
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3 || !argv[2])
	{
		ft_printf("Error, Your input must contain");
		ft_printf(" <PROCESS PID> <MESSAGE THAT MUST BE SENT>");
		exit(1);
	}
	send_string_bit(ft_atoi(argv[1]), argv[2]);
	return (0);
}

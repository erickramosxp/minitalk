/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erramos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 18:52:22 by erramos           #+#    #+#             */
/*   Updated: 2023/12/28 21:18:12 by erramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdlib.h>
void	signal_action(int pid, char *str)
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
			usleep(150);
		}
		str++;
		i = 0;
	}
}

// Validate the number of arguments

// Convert the server ID (PID) to an integer and
// send the message using the signal_action function

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		printf("Invalid number of arguments.\n");
		printf("Format: [./client <SERVER ID (PID)> <STRING>]\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		signal_action(atoi(argv[1]), argv[2]);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erramos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 19:21:27 by erramos           #+#    #+#             */
/*   Updated: 2024/01/05 20:15:39 by erramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	print_bit(int bit)
{
	static int				i;
	static unsigned char	c;

	if (bit == SIGUSR2)
		c = c << 1;
	else if (bit == SIGUSR1)
		c = (c << 1) | 0b00000001;
	i++;
	if (i == 8)
	{
		ft_printf("%c", c);
		i = 0;
		c = 0;
	}
}

int	main(void)
{
	ft_printf("\t\t\t\t\t MINITALK\n");
	ft_printf("\t\t\t\t     Server PID: %d\n", getpid());
	while (1)
	{
		signal(SIGUSR1, print_bit);
		signal(SIGUSR2, print_bit);
		pause();
	}
	return (0);
}

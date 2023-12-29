/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erramos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 18:52:22 by erramos           #+#    #+#             */
/*   Updated: 2023/12/29 17:34:53 by erramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void    send_string_bit(int pid, char *str)
{
        int     i;
        int     c;

        i = 0;
        while(*str)
        {
                c = *(str);
                while (i < 8)
                {
                        if (c << i & 0b10000000)
                                kill(pid, SIGUSR1);
                        else
                                kill(pid, SIGUSR2);
                        i++;
			usleep(200);
                }
                str++;
		i = 0;
        }
}

int     main(int argc, char **argv)
{
        send_string_bit(ft_atoi(argv[1]), argv[2]);
	return (0);
}

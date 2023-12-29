/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erramos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 18:52:22 by erramos           #+#    #+#             */
/*   Updated: 2023/12/29 15:10:13 by erramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdlib.h>

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
                }
                i = 0;
                str++;
        }
}

int     main(int argc, char **argv)
{
        int     a;
        int     pid;

        pid = atoi(argv[1]);
        send_string_bit(pid, argv[2]);
}

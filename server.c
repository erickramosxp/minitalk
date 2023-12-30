/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erramos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 19:21:27 by erramos           #+#    #+#             */
/*   Updated: 2023/12/30 15:02:28 by erramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void    print_num(int bit)
{
        static int      i;
        static unsigned char    c;

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

int     main(void)
{
        ft_printf("%d\n", getpid());
        while (1)
        {
                signal(SIGUSR1, print_num);
                signal(SIGUSR2, print_num);
                usleep(200);
        }
        return (0);
}

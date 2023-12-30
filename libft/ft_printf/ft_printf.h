/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erramos <erramos@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:51:41 by erramos           #+#    #+#             */
/*   Updated: 2023/11/14 14:47:50 by erramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "./libft/libft.h"

int	ft_printf(const char *s, ...);
int	ft_printhex(const char c, unsigned int nb);
int	ft_printpoint(unsigned long long nb);
int	ft_printnb(int nb);
int	ft_printu(unsigned int nb);
int	count_hex(unsigned int nb);

#endif

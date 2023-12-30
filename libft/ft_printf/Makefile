# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erramos <erramos@student.42.rio>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/09 15:45:17 by erramos           #+#    #+#              #
#    Updated: 2023/11/14 14:52:53 by erramos          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CFLAGS = cc -Wall -Wextra -Werror

FILES =	ft_printf.c ft_printhex.c ft_printpoint.c ft_printnb.c \
	ft_printu.c ft_counthex.c

DIRLIB = libft/

LIBFT =	ft_itoa.c ft_putchar.c ft_putstr.c \
	ft_strdup.c ft_strlen.c

OBJS = $(FILES:.c=.o) $(LIBFT:.c:.o)

all: $(NAME)

$(NAME):
	$(CFLAGS) -I. -c $(FILES) $(addprefix libft/,$(LIBFT))
	ar rcs $(NAME) $(OBJS) $(LIBFT:.c=.o)

clean:
	rm -f $(OBJS)
	rm -f $(LIBFT:.c=.o)

fclean: clean
	rm -f $(NAME)

re:	fclean all

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erramos <erramos@student.42.rio>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/29 16:24:04 by erramos           #+#    #+#              #
#    Updated: 2023/12/29 17:26:18 by erramos          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server.c
CLIENT = client.c
NAME = minitalk.a

all:	$(NAME)

$(NAME):
	$(MAKE) -C ./libft/ft_printf/
	$(MAKE) -C ./libft/
	ar -r ./libft/libft.a ./libft/ft_printf/*.o
	cp ./libft/libft.a ./
	mv libft.a $(NAME)

clean:

fclean:

re:



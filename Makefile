# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erramos <erramos@student.42.rio>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/29 16:24:04 by erramos           #+#    #+#              #
#    Updated: 2024/01/05 19:44:14 by erramos          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server.c
CLIENT = client.c
NAME = minitalk.a

all:	$(NAME)

$(NAME):
	@$(MAKE) -C ./libft/ft_printf/
	@$(MAKE) -C ./libft/
	@ar -r ./libft/libft.a ./libft/ft_printf/*.o
	@cp ./libft/libft.a ./
	@mv libft.a $(NAME)
	@cc client.c $(NAME) -o client
	@cc server.c $(NAME) -o server
	@echo "Server and Client create."

clean:
	@$(MAKE) clean -C ./libft/ft_printf/
	@$(MAKE) clean -C ./libft/

fclean: clean
	@$(MAKE) fclean -C ./libft/ft_printf/
	@$(MAKE) fclean -C ./libft/
	@rm -rf $(NAME) server client
	@echo "All files deleted."

re:	fclean all

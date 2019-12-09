# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lvoyance <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/19 10:32:39 by lvoyance          #+#    #+#              #
#    Updated: 2019/09/22 18:12:22 by lvoyance         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRCS = main.c spliter.c validator.c solver.c ./libft/libft.a

INCLS = ./includes



all: $(NAME)

$(NAME): $(SRCS) fillit.h
	gcc -Wall -Wextra -Werror $(SRCS) -o fillit


clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

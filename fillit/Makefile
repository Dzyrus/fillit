# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lvoyance <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/19 10:32:39 by lvoyance          #+#    #+#              #
#    Updated: 2019/12/19 11:21:09 by lvoyance         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = validator.c \
            spliter.c \
            main.c \
            solver.c

LFT = ./libft/libft.a

FLAGS = -Wall -Wextra -Werror

//.PHONY: all clean fclean re

all: $(NAME)
    gcc -I  $(FLAGS) -c $(SRC) $(LFT) -o $(NAME)

clean:
    /bin/rm -f $(NAME)
fclean: clean
    /bin/rm -f $(NAME)
re: fclean all

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zaldhahe <zaldhahe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/30 22:24:19 by zaldhahe          #+#    #+#              #
#    Updated: 2024/06/30 22:24:19 by zaldhahe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = push_swap.c checkers.c parsing.c utils1.c utils2.c utils3.c utils4.c \
op1.c op2.c op3.c op4.c sort1.c sort2.c

OBJ = $(SRC:.c=.o)

CC = cc

CFLAGS = -Wall -Werror -Wextra -fsanitize=address -g

COMPILE = $(CC) $(CFLAGS)

all : $(NAME)

$(NAME) : $(OBJ)
	$(COMPILE) $(OBJ) -o $(NAME)

clean : 
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
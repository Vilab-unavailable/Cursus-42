# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vilabard <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/08 17:26:35 by vilabard          #+#    #+#              #
#    Updated: 2024/08/08 17:52:26 by vilabard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
FLAGS = -Wall -Wextra -Werror

SRC = ft_putchar.c \
      ft_swap.c \
      ft_putstr.c \
      ft_strlen.c \
      ft_strcmp.c \
      ft.h \

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@
	
.PHONY: all clean

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean $(NAME)


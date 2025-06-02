# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vilabard <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/04 22:41:12 by vilabard          #+#    #+#              #
#    Updated: 2024/08/04 22:50:15 by vilabard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rush-02

CC = gcc
FLAGS = -Wall -Wextra -Werror

SRC = main.c \
      parse.c \
      ft_error.c \
      ft_print_0.c \
      print_nbr.c \
      ft_utilities.c \
      ft_utilities_2.c \
      ft_cut_number.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean $(NAME)

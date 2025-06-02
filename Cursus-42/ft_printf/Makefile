# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vilabard <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/02 19:35:07 by vilabard          #+#    #+#              #
#    Updated: 2024/12/02 19:35:09 by vilabard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = libftprintf.a

CC = cc
FLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c     ft_printhexa.c\
	  ft_printnbr.c  ft_printunbr.c  ft_printptr.c\


OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	ar -rcs $(NAME) $(OBJ)

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@
	
.PHONY: all clean

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean $(NAME)

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vilabard <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/02 19:35:07 by vilabard          #+#    #+#              #
#    Updated: 2025/08/02 19:22:41 by vilabard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
HEADER = pipex.h

SRC = main.c\

OBJ = $(SRC:.c=.o)

NAME = pipex

CC = cc -g

FLAGS = -Wall -Wextra -Werror

LIBFT_PATH = ./libft

LIBFT = $(LIBFT_PATH)/libft.a

all : $(NAME)

$(NAME) : $(OBJ)
	make -C $(LIBFT_PATH) all
	$(CC) $(FLAGS) $(OBJ) ./libft/libft.a -o $(NAME)

%.o : %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

clean :
	rm -f $(OBJ)
	make -C $(LIBFT_PATH) clean

fclean : clean
	rm -f $(NAME)
	make -C $(LIBFT_PATH) fclean

re : fclean all

.PHONY: all clean fclean re

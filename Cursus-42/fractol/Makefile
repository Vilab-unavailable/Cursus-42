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
HEADER = fractol.h

SRC =	main.c	ft_calc.c	ft_exit.c	ft_param.c \
		ft_convert_base.c	ft_inits.c	ft_utils.c \
		ft_atox.c	ft_key_mouse.c \

OBJ = $(SRC:.c=.o)

NAME = fractol

CC = cc

FLAGS = -Wall -Wextra -Werror

LIBFT_PATH = ./libft

MLX_PATH = ./minilibx

LIBFT = $(LIBFT_PATH)/libft.a

MLX = $(MLX_PATH)/libmlx_Linux.a

MLX_FLAG = -I$(MLX_PATH) -L$(MLX_PATH) -lmlx -lXext -lX11
all : $(NAME)

$(NAME) : $(OBJ) $(LIBFT) $(MLX)
	$(CC) $(FLAGS) $(OBJ) $(LIBFT) $(MLX_FLAG) -o $(NAME) -lm -lz

$(LIBFT) :
	make -sC $(LIBFT_PATH) all

$(MLX) :
	make -sC $(MLX_PATH) all

%.o : %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

clean :
	rm -f $(OBJ)
	make -sC $(LIBFT_PATH) clean
	make -sC $(MLX_PATH) clean

fclean : clean
	rm -f $(NAME)
	make -sC $(LIBFT_PATH) fclean
	make -sC $(MLX_PATH) clean

re : fclean all

.PHONY: all clean fclean re

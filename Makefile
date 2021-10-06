# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/06 10:57:58 by tblaase           #+#    #+#              #
#    Updated: 2021/10/06 11:35:39 by tblaase          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc

CFLAGS = -Wall -Wextra -Werror

MLX_PATH = mlx/

MLX_LIB = $(MLX_PATH)libmlx.a

MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit

CFILES = \
		hook.c\
		so_long.c\

OBJECTS = $(CFILES:.c=.o)

all: $(NAME)

subsystem:
	make -C $(MLX_PATH) all

compile:
	$(CC) $(CFLAGS) -Imlx -c $(CFILES) -o $(OBJECTS)

$(NAME): subsystem compile
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJECTS) $(MLX_LIB) -o $(NAME)

clean:
	make -C $(MLX_PATH) clean
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

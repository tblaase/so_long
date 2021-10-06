# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/06 12:53:31 by tblaase           #+#    #+#              #
#    Updated: 2021/10/06 18:35:52 by tblaase          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

CFILES = \
		ft_atoi.c\
		ft_calloc.c\
		ft_count_c.c\
		ft_count_lines.c\
		ft_line_length.c\
		ft_strchr.c\
		ft_strlen.c\

OBJECTS = $(CFILES:.c=.o)

all: $(NAME)

compile:
	$(CC) $(CFLAGS) -c $(CFILES)

$(NAME): compile
	ar -rcs $(NAME) $(OBJECTS)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

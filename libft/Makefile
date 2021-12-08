# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/06 12:53:31 by tblaase           #+#    #+#              #
#    Updated: 2021/12/08 17:20:31 by tblaase          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

Y = "\033[33m"
R = "\033[31m"
G = "\033[32m"
B = "\033[34m"
X = "\033[0m"
UP = "\033[A"
CUT = "\033[K"

CFILES = \
		ft_atoi.c\
		ft_calloc.c\
		ft_count_c.c\
		ft_count_lines.c\
		ft_line_length.c\
		ft_strchr.c\
		ft_strjoin.c\
		ft_strlen.c\
		ft_strnstr.c\

OBJECTS = $(CFILES:.c=.o)

%.o : %.c
	@$(CC) $(CFLAGS) -c -o $@ $<
	@printf $(UP)$(CUT)
	@echo $(Y)Compiling [$<]...$(X)

all: $(NAME)

$(NAME): $(OBJECTS)
	@printf $(UP)$(CUT)
	@echo $(Y)Compiling [$(NAME)]...$(X)
	@ar -rcs $(NAME) $(OBJECTS)
	@ranlib $(NAME)
	@echo $(G)Finished [$(NAME)]$(X)
	@echo

clean:
	@rm -f $(OBJECTS)
	@echo $(R)Removed [$(OBJECTS)]$(X)

fclean: clean
	@rm -f $(NAME)
	@echo $(R)Removed [$(NAME)]$(X)

re: fclean all

.PHONY: all clean fclean re

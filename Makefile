# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: btenzlin <btenzlin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/27 16:48:18 by btenzlin          #+#    #+#              #
#    Updated: 2022/01/28 12:37:42 by btenzlin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc
FLAGS = -Wall -Wextra -Werror
RM = rm -rf

SRCS = main.c \
		get_next_line.c \
		get_next_line_utils.c

OBJS = ${SRCS:.c=.o}

all: $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -Llibmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

re: fclean all

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

.PHONY: all clean fclean re
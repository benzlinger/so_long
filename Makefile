# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: btenzlin <btenzlin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/27 16:48:18 by btenzlin          #+#    #+#              #
#    Updated: 2022/02/02 13:54:16 by btenzlin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc
FLAGS = -Wall -Wextra -Werror
RM = rm -rf
NORM = norminette

GREEN = "\033[1;32m"
NO_COLOR = "\033[0m"

SRCS = main.c \
		get_next_line.c \
		get_next_line_utils.c \
		map.c \
		map_utils.c \
		territory.c \
		game.c

OBJS = ${SRCS:.c=.o}

all: $(NAME)

$(NAME) : $(OBJS)
	@printf "%b" $(GREEN) "creating so_long...\n\n" $(NO_COLOR)
	@$(CC) $(FLAGS) $(OBJS) -Llibmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@printf "%b" $(GREEN) "done!\n" $(NO_COLOR)

re: fclean all

clean:
	@printf "%b" $(GREEN) "removing object files...\n" $(NO_COLOR)
	@$(RM) $(OBJS)
	@printf "%b" $(GREEN) "done!\n" $(NO_COLOR)

fclean: clean
	@printf "%b" $(GREEN) "removing executable...\n" $(NO_COLOR)
	@$(RM) $(NAME)
	@printf "%b" $(GREEN) "done!\n" $(NO_COLOR)

norm:
	@$(NORM) $(SRCS) so_long.h
	@printf "%b" $(GREEN) "OK!\n" $(NO_COLOR)

.PHONY: all clean fclean re norminette
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kgavrilo <kgavrilo@student.42.us.org>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/26 20:40:34 by kgavrilo          #+#    #+#              #
#    Updated: 2019/12/15 22:19:59 by kgavrilo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
FLAGS = -Wall -Wextra -Werror -Iincludes
SRC_DIR = src/
FILES = main draw hooks map projection win_init
LIBFT = libft/
MINILIBX = minilibx/

SRC = $(patsubst %, $(SRC_DIR)%, $(addsuffix .c, $(FILES)))
OBJ = $(SRC:.c=.o)

.PHONY: all clean fclean re build leaks

%.o: %.c
	gcc -c -o $@ $< $(FLAGS)

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBFT)
	make -C $(MINILIBX)
	gcc $(OBJ) -o $(NAME) -L libft -lft -L minilibx -lmlx -framework OpenGL -framework AppKit

clean:
	rm -f $(OBJ)
	make -C $(LIBFT) clean
	make -C $(MINILIBX) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT) fclean
	make -C $(MINILIBX) fclean

re:	fclean all

build: $(OBJ)
	rm -f $(NAME)
	rm -rf fdf.sSYM
	gcc $(OBJ) -o $(NAME) -L libft -lft -L minilibx -lmlx -framework OpenGL -framework AppKit -g

leaks: build
	rm -f valgrind-out.txt
	~/bin/valgrind/bin/valgrind --leak-check=yes --track-origins=yes --log-file=valgrind-out.txt ./fdf ./maps/42.fdf

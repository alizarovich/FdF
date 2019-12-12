# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kgavrilo <kgavrilo@student.42.us.org>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/26 20:40:34 by kgavrilo          #+#    #+#              #
#    Updated: 2019/12/11 20:35:35 by kgavrilo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
FLAGS = -Wall -Wextra -Werror -I./
SRC = main.c draw.c hooks.c map.c projection.c win_init.c
LIBFT = libft/
MINILIBX = minilibx/

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

build:
	rm -f $(NAME)
	rm -rf fdf.sSYM
	gcc -c $(SRC) $(FLAGS) -g
	gcc $(OBJ) -o $(NAME) -L libft -lft -L minilibx -lmlx -framework OpenGL -framework AppKit -g
	#rm -f $(OBJ)

leaks: build
	rm -f valgrind-out.txt
	~/bin/valgrind/bin/valgrind --leak-check=yes --track-origins=yes --log-file=valgrind-out.txt ./fdf ./maps/42.fdf

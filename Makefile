# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kgavrilo <kgavrilo@student.42.us.org>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/26 20:40:34 by kgavrilo          #+#    #+#              #
#    Updated: 2019/11/29 19:02:29 by kgavrilo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
FLAGS = -Wall -Wextra -Werror -I./
SRC = main.c
LIBFT = libft/
MINILIBX = minilibx/

OBJ = $(SRC:.c=.o)

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
	gcc -c $(SRC) $(FLAGS) -g
	gcc $(OBJ) -o $(NAME) -L libft -lft -L minilibx -lmlx -framework OpenGL -framework AppKit -g
	#rm -f $(OBJ)

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kgavrilo <kgavrilo@student.42.us.org>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/26 20:40:34 by kgavrilo          #+#    #+#              #
#    Updated: 2019/11/29 20:10:08 by kgavrilo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
FLAGS = -Wall -Wextra -Werror -I./
SRC = main.c
LIBFT = libft/

OBJ = $(SRC:.c=.o)

%.o: %.c
	gcc -c -o $@ $< $(FLAGS)

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBFT)
	gcc $(OBJ) -o $(NAME) -L libft -lft

clean:
	rm -f $(OBJ)
	make -C $(LIBFT) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT) fclean

re:	fclean all

build:
	rm -f $(NAME)
	gcc -c $(SRC) $(FLAGS) -g
	gcc $(OBJ) -o $(NAME) -L libft -lft
	rm -f $(OBJ)

test:
	gcc $(FLAGS) -I minilibx -L minilibx -lmlx -framework OpenGL -framework AppKit $(SRC)

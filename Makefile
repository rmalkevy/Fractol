# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmalkevy <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/10 20:40:36 by rmalkevy          #+#    #+#              #
#    Updated: 2017/03/14 15:52:17 by rmalkevy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC = write_picture.c main.c fractal.c control.c mandelbrot.c color.c

OBJ = $(SRC:.c=.o)

CC = gcc

FLGS = -Wall -Wextra -Werror

INC = ./

LIB = -L ./libft/ -lft
LIBMLX = -L ./minilibx/ -lft

all: $(NAME)

$(NAME): $(OBJ)
		make -C ./libft/
		$(CC) -o $(NAME) $(OBJ) $(LIB) $(LIBMLX) -lmlx -framework OpenGL -framework AppKit -O3

%.o: %.c
		$(CC) $(FLGS) -c $<

clean:
		make -C ./libft/ clean
		rm -rf $(OBJ)

fclean: clean
		make -C ./libft/ fclean
		rm -f $(NAME)

re: fclean all
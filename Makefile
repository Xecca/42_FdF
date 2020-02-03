# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aponomar <aponomar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/21 15:35:39 by aponomar          #+#    #+#              #
#    Updated: 2020/02/02 15:36:48 by aponomar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = gcc
FLAGS = -Wall -Wextra -Werror
FRAMEWORKS = -framework OpenGL -framework AppKit
SOURCE = *.c
INCLUDE = libft/libft.a
MIMILIBX = minilibx_macos/libmlx.a
DEBUG = -g

all:
	@make -C libft/ all
	gcc *.c $(FLAGS) $(INCLUDE) $(MIMILIBX) $(DEBUG) -o $(NAME) $(FRAMEWORKS)
	
fclean:
	rm -rf $(NAME)
	@make -C libft/ fclean

re: fclean all

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aponomar <aponomar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/21 15:35:39 by aponomar          #+#    #+#              #
#    Updated: 2020/01/29 17:49:00 by aponomar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = gcc
FLAGS = -Wall -Wextra -Werror
FRAMEWORKS = -framework OpenGL -framework AppKit
SOURCE = *.c
INCLUDE = libft/libft.a

all:
	gcc *.c $(FLAGS) libft/libft.a minilibx_macos/libmlx.a -o fdf $(FRAMEWORKS)
	
fclean:
	rm -rf fdf

re: fclean all
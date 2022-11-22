# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hdagdagu <hdagdagu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/16 17:48:50 by hdagdagu          #+#    #+#              #
#    Updated: 2022/11/22 18:39:59 by hdagdagu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

cc = gcc
SRC = so_long.c get_array.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c showimage.c check.c so_long_utils.c ft_printf/ft_printf.c  ft_printf/ft_putchar.c ft_printf/ft_putstr.c ft_printf/ft_putnbr.c key_hook.c mvplayer.c
BONUSSRC = so_long_bonus.c get_array.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c showimage.c check.c so_long_utils.c ft_animation.c ft_printf/ft_printf.c  ft_printf/ft_putchar.c ft_printf/ft_putstr.c ft_printf/ft_putnbr.c  key_hook.c mvplayer.c

NAME = a.out
OBJ = $(SRC:.c=.o)

Flags = -Wall -Wextra -Werror

$(NAME): 
	@$(CC) $(SRC) $(Flags) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) 
bonus :	
	@$(CC) $(BONUSSRC) $(Flags) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) 
fclean :
	@rm -rf $(OBJ) $(NAME) 
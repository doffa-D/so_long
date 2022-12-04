# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hdagdagu <hdagdagu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/16 17:48:50 by hdagdagu          #+#    #+#              #
#    Updated: 2022/11/29 13:04:14 by hdagdagu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

cc = gcc

SRC = 	so_long.c \
		get_array.c \
		get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c \
		showimage.c \
		check.c \
		so_long_utils.c \
		ft_printf/ft_printf.c \
		ft_printf/ft_putchar.c \
		ft_printf/ft_putstr.c \
		ft_printf/ft_putnbr.c \
		key_hook.c \
		mvplayer.c \
		ft_close.c \

BONUSSRC = 	bonus/so_long_bonus.c \
			bonus/get_array_bonus.c \
			bonus/check_bonus.c \
			bonus/ft_animation.c \
			get_next_line/get_next_line.c \
			get_next_line/get_next_line_utils.c \
			ft_printf/ft_printf.c \
			ft_printf/ft_putchar.c \
			ft_printf/ft_putstr.c \
			ft_printf/ft_putnbr.c \
			so_long_utils.c \
			key_hook.c \
			mvplayer.c \
			showimage.c \
			ft_close.c \

NAME = so_long
OBJ = $(SRC:.c=.o)

Flags = -Wall -Wextra -Werror

$(NAME): 
	@$(CC) $(SRC) $(Flags) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) 
bonus :	$(NAME)
	@$(CC) $(BONUSSRC) $(Flags) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) 
fclean :
	@rm -rf $(OBJ) $(NAME) 
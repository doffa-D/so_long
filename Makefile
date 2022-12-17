# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hdagdagu <hdagdagu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/16 17:48:50 by hdagdagu          #+#    #+#              #
#    Updated: 2022/12/16 17:35:16 by hdagdagu         ###   ########.fr        #
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
		protect.c \
		freesss.c \

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
			protect.c \
			bonus/redanime.c \
			ft_strtrim.c \
			bonus/animove.c \
			bonus/whill.c \
			freesss.c \

		
color =\033[0;35m
END=\033[0m


define SO_LONG

   ▄████████  ▄██████▄        ▄█        ▄██████▄  ███▄▄▄▄      ▄██████▄  
  ███    ███ ███    ███      ███       ███    ███ ███▀▀▀██▄   ███    ███ 
  ███    █▀  ███    ███      ███       ███    ███ ███   ███   ███    █▀  
  ███        ███    ███      ███       ███    ███ ███   ███  ▄███        
▀███████████ ███    ███      ███       ███    ███ ███   ███ ▀▀███ ████▄  
         ███ ███    ███      ███       ███    ███ ███   ███   ███    ███ 
   ▄█    ███ ███    ███      ███▌    ▄ ███    ███ ███   ███   ███    ███ 
 ▄████████▀   ▀██████▀       █████▄▄██  ▀██████▀   ▀█   █▀    ████████▀  
                             ▀                                           
						 
endef
export SO_LONG
NAME = so_long
OBJ = $(SRC:.c=.o)
BONUSOBJ = $(BONUSSRC:.c=.o)

Flags = -Wall -Wextra -Werror

$(NAME): $(OBJ)
	@$(CC) $(OBJ) $(Flags) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@echo "$(color) $$SO_LONG"
	
all	:$(NAME)

bonus :	$(BONUSOBJ) 
	@$(CC) $(Flags) $(BONUSOBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@echo "$(color) $$SO_LONG"

%.o:%.c
	$(CC) $(Flags) -c $^ -o $@ 

fclean:
	rm -rf $(NAME) $(OBJ) $(BONUSOBJ)
clean:
	rm -rf $(OBJ) $(BONUSOBJ)
re:fclean $(NAME)
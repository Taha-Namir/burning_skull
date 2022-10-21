# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tnamir <tnamir@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/12 14:39:23 by tnamir            #+#    #+#              #
#    Updated: 2022/02/14 14:04:34 by tnamir           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

HEADER = so_long.h

SRC = ./mainfiles/map.c ./mainfiles/mapreader.c ./mainfiles/image.c ./mainfiles/window.c ./mainfiles/main.c ./mainfiles/hooks.c ./mainfiles/putimage.c ./gnl/get_next_line.c ./gnl/get_next_line_utils.c ./gnl/ft_split.c ./gnl/indexof.c ./gnl/ft_itoa.c

all : $(NAME) execute

$(NAME) : mlx $(SRC) $(HEADER)
	@cc $(SRC) -Ofast -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -Wall -Wextra -Werror -o $(NAME)

mlx :
	$(MAKE) -C ./mlx_linux

execute :
	@./so_long sprites/map2.ber

clean : 
	@rm -rf $(NAME)
	$(MAKE) clean -C ./mlx_linux

fclean : clean
	@rm -rf $(NAME)

re : fclean all
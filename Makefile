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

HEADER = ./mainfiles/so_long.h

FCT = ./mainfiles/map.c ./mainfiles/mapreader.c ./mainfiles/image.c ./mainfiles/window.c ./mainfiles/main.c ./mainfiles/hooks.c ./mainfiles/putimage.c ./gnl/get_next_line.c ./gnl/get_next_line_utils.c ./gnl/ft_split.c ./gnl/indexof.c ./gnl/ft_itoa.c

OBJ = map.o mapreader.o image.o window.o main.o hooks.o putimage.o get_next_line.o get_next_line_utils.o ft_split.o indexof.o ft_itoa.o

all : $(NAME)

$(NAME) : $(OBJ) $(FCT) $(HEADER)
	@cc $(FCT) -lmlx -framework OpenGL -framework AppKit -Wall -Wextra -Werror -o $(NAME)

$(OBJ) : $(FCT) $(HEADER)
	@cc -Wall -Wextra -Werror -c $(FCT)

clean : 
	@rm -rf $(OBJ)

fclean : clean
	@rm -rf $(NAME)

re : fclean all
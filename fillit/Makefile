# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgaia <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/11 23:03:39 by rgaia             #+#    #+#              #
#    Updated: 2017/10/12 00:03:52 by rgaia            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = fillit.c parse_tetrimino_file.c

FLAGS = -L../libft/. -lft -o

all: $(NAME)

$(NAME):
		@gcc $(FLAGS) $(NAME) $(SRC)

clean:
		@rm -rf *.o

fclean: clean
		@rm -rf $(NAME)

re: fclean 
	@make


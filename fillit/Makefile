# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgaia <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/11 23:03:39 by rgaia             #+#    #+#              #
#    Updated: 2017/10/14 12:22:25 by rgaia            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = fillit.c \
	  hardcoded_tetrimino.c insert_array.c parse_tetrimino_file.c \

FLAGS = -Wall -Wextra -Werror -L../libft/. -lft -o

all: $(NAME)

$(NAME):
		@gcc $(FLAGS) $(NAME) $(SRC)

clean:
		@rm -rf *.o

fclean: clean
		@rm -rf $(NAME)

re: fclean 
	@make


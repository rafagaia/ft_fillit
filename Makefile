# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgaia <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/19 21:33:28 by rgaia             #+#    #+#              #
#    Updated: 2017/10/04 17:21:22 by rgaia            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 

SRC = 

FLAGS = -c -Wall -Werror -Wextra #add libft.a flags and to compilation

all: $(NAME)

$(NAME):
		@gcc $(FLAGS) $(SRC)
		@ar -rc $(NAME) *.o

clean:
		@rm -rf *.o

fclean: clean
		@rm -rf $(NAME)

re: fclean 
	@make


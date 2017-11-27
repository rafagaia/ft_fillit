# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eguajard <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/02 10:38:16 by eguajard          #+#    #+#              #
#    Updated: 2017/11/27 09:05:54 by rgaia            ###   ########.fr        #
#    Updated: 2017/11/22 16:46:09 by rgaia            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			fillit

COMPILA =		gcc -Wall -Wextra -Werror -c

T_COMPILA =		gcc -Wall -Wextra -Werror -g -c

CFILES =		fillit.c \
				valid_integration.c \
				valid_read_and_split.c \
				valid_shape.c \
				tetrimino.c \
				solve.c \
				solve_utils.c \
				output.c \

TEST_FILES =	test/src/test_checkfit.c \
				valid_integration.c \
				valid_read_and_split.c \
				valid_shape.c \
				tetrimino.c \
				solve.c \
				solve_utils.c \
				output.c \

OFILES =		*.o

LINK_FLAGS =	-L../libft/. -lft

all: $(NAME)

$(NAME):
	$(T_COMPILA) $(TEST_FILES)
	gcc $(LINK_FLAGS) $(OFILES) -o $(NAME)

clean: 
	@/bin/rm -f $(OFILES)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

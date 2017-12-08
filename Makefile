# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eguajard <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/02 10:38:16 by eguajard          #+#    #+#              #
#    Updated: 2017/12/05 19:26:27 by eguajard         ###   ########.fr        #
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
				tetrimino_utils.c \
				solve.c \
				solve_utils.c \
				output.c \

TEST_FILES =	test.c \
				valid_integration.c \
				valid_read_and_split.c \
				valid_shape.c \
				tetrimino.c \
				tetrimino_utils.c \
				solve.c \
				solve_utils.c \
				output.c \

OFILES =		*.o

TEST =			$(T_COMPILA) $(TEST_FILES)

RUN =			$(COMPILA) $(CFILES)

all: $(NAME)

$(NAME):
	@cd libft && make
	$(RUN)
	gcc $(LINK_FLAGS) $(OFILES) libft/libft.a -o $(NAME)

clean:
	@cd libft && make clean
	@/bin/rm -f $(OFILES)

fclean: clean
	@cd libft && make fclean
	@/bin/rm -f $(NAME)

re: fclean all

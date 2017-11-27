/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgaia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 20:24:49 by rgaia             #+#    #+#             */
/*   Updated: 2017/11/15 21:26:27 by rgaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

//char	**valid_file_format(int fd);
//t_list	*read_tetriminos(char **file_tetriminos);

void	exit_failure(char *str)
{
	ft_putstr(str);
	exit(EXIT_FAILURE);
}


int		print_tetriminos(t_list *tetriminos)
{
	char	*str;
	int		size;
	t_piece	*tetri;

	size = 0;
	while (tetriminos->next)
	{
		size++;
		tetri = tetriminos->content;
		str = tetri->piece;
		while (*str)
			(*str++ != '.' ? ft_putchar(tetri->letter) : ft_putchar('.'));
		ft_putchar('\n');
		tetriminos = tetriminos->next;
	}
	return (size);
}

int		check_tail(t_list *tetriminos)
{
	while (tetriminos->next)
		tetriminos = tetriminos->next;
	if (tetriminos->next == NULL)
		ft_putendl("TETRIMINOS->NEXT == NULL");
	if (tetriminos->content == NULL)
		ft_putendl("CONTENT NULL");
	return (0);
}

int		test_list(t_list *tetriminos)
{
	int		list_size;
	
	//print_tetriminos
	ft_putendl("TETRIMINOS: ");
	list_size = print_tetriminos(tetriminos);
	//print list_size
	ft_putendl("NUMBER OF TETRIMINOS: ");
	ft_putnbr(list_size);
	ft_putchar('\n');
	//check tail of list
	check_tail(tetriminos);
	return (1);
}

int		main(int argc, char **argv)
{
	int			fd;
	char		**file_tetriminos;
	t_list		*tetriminos;

	//Inputs
	//	read file, and return a List containing a Tetrimino Struct at each element
	if (argc != 2)
		exit_failure("usage: ./fillit source_file");
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		exit_failure("error");
	if ((file_tetriminos = valid_file_format(fd)) == NULL)
		exit_failure("error");
	tetriminos = read_tetriminos(file_tetriminos);
	if (test_list(tetriminos) == 0)
		exit_failure("BAD LIST");

	return (0);
}

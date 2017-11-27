/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgaia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 15:06:31 by rgaia             #+#    #+#             */
/*   Updated: 2017/11/21 16:33:33 by rgaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

//char	**valid_file_format(int fd);
//t_list	*read_tetriminos(char **file_tetriminos);

/*
** This is the entry point to our Fillit program
*/

void	exit_failure(char *str)
{
	ft_putstr(str);
	exit(EXIT_FAILURE);
}


int		main(int argc, char **argv)
{
	int			fd;
	char		**file_tetriminos;
	t_list		*tetriminos;
	t_map		*map;

	//Inputs
	//	read file, and return a List containing a Tetrimino Struct at each element
	if (argc != 2)
		exit_failure("usage: ./fillit source_file");
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		exit_failure("error");
	if ((file_tetriminos = valid_file_format(fd)) == NULL)
		exit_failure("error");
	tetriminos = read_tetriminos(file_tetriminos);
	printf("FINISHED INSERTING TETRIMINOS TO LIST\n");
	map = solve(tetriminos);
	printf("ENTERING PRINT MAP\n");
	print_map(map);
	//file_tetriminos_delete(&file_tetriminos);
	//map_delete(&map);
	//tetriminos_delete(&tetriminos);
	return (0);
}

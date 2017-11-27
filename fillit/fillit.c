/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgaia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 18:52:41 by rgaia             #+#    #+#             */
/*   Updated: 2017/11/25 16:31:35 by rgaia            ###   ########.fr       */
/*   Updated: 2017/11/23 14:30:33 by rgaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** This is the entry point to our Fillit program
*/

void	exit_failure(char *str)
{
	ft_putstr(str);
	exit(EXIT_FAILURE);
}

//include free_memory functions here

int		main(int argc, char **argv)
{
	int			fd;
	char		**file_tetriminos;
	t_map		*map;
	t_list		*tetriminos;

	//Inputs
	//	read file, and return a List containing a Tetrimino Struct at each element
	if (argc != 2)
		exit_failure("usage: ./fillit source_file");
	//Validation.c
	if ((fd = open(argv[1], O_RDONLY)) < 1)
		exit_failure("error");
	if ((file_tetriminos = valid_file_format(fd)) == NULL)
		exit_failure("error");
	//Tetrimino.c
	tetriminos = read_tetriminos(file_tetriminos);
	//Solve.c
	//	receive a List with tetriminos, and 
	//	output a Map Struct filled with Tetrimino pieces by their letter
	map = solve(tetriminos);
	//Output.c
	//	receive a Map Struct, and output to Standard Out
	print_map(map);
	//free_file_tetriminos(&file_tetriminos);
	//free_tetriminos(&tetriminos);
	//free_map(&map);
	return (0);
}

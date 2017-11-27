/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_insert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgaia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 03:45:22 by rgaia             #+#    #+#             */
/*   Updated: 2017/11/21 16:21:18 by rgaia            ###   ########.fr       */
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

int		main(int argc, char **argv)
{
	int			fd;
	char		**file_tetriminos;
	t_list		*tetriminos;
	t_map		*map;
	t_point		*point;
	t_piece		*piece;

	//Inputs
	//	read file, and return a List containing a Tetrimino Struct at each element
	if (argc != 4)
		exit_failure("usage: ./fillit source_file\n");
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		exit_failure("error");
	if ((file_tetriminos = valid_file_format(fd)) == NULL)
		exit_failure("error");
	tetriminos = read_tetriminos(file_tetriminos);
	point = point_new(ft_atoi(argv[2]), ft_atoi(argv[3]));
	piece = tetriminos->content;
	map = init_map(7);
	if (check_fit(piece->piece, point, map->grid, map->size))
	{
		printf("IT FITS\n");
		io_tetrimino(piece->letter, piece->piece, point, map);
	}
	//io_tetrimino(CHR_FIELD, piece->piece, point, map);
	ft_memdel((void**)&point);
	print_map(map);
	return (0);
}

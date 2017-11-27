/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_checkfit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgaia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 23:44:03 by rgaia             #+#    #+#             */
/*   Updated: 2017/11/24 15:46:45 by rgaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fillit.h"

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
	t_piece		*piece;
	t_map		*map;
	t_point		*point;

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
	map = init_map(3);
	piece = (t_piece *)(tetriminos->content);
	
	if (check_fit(piece->piece, point, map->grid, map->size))
	{
		ft_putendl("IT FITS");
		io_tetrimino(piece->letter, piece->piece, point, map);
	}
	ft_memdel((void**)&point);
	print_map(map);
	return (0);
}

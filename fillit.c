/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgaia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 09:48:50 by rgaia             #+#    #+#             */
/*   Updated: 2017/12/05 17:18:36 by eguajard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** This is the entry point to our Fillit program
*/

void			exit_failure(char *str)
{
	ft_putstr(str);
	exit(EXIT_FAILURE);
}

static t_map	*check_2b2(t_piece *tetri)
{
	t_map		*map;

	if (g_num_tetriminos != 1)
		return (NULL);
	if (ft_strequ(tetri->piece, "##...##") == 0)
		return (NULL);
	map = init_map(2);
	ft_strcpy(map->grid[0], "AA");
	ft_strcpy(map->grid[1], "AA");
	return (map);
}

/*
** free_file_tetriminos(&file_tetriminos);
** free_tetriminos(&tetriminos);
** free_map(&map);
*/

int				main(int argc, char **argv)
{
	int			fd;
	char		**file_tetriminos;
	t_map		*map;
	t_list		*tetriminos;

	if (argc != 2)
		exit_failure("usage: ./fillit source_file");
	if ((fd = open(argv[1], O_RDONLY)) < 1)
		exit_failure("error\n");
	if ((file_tetriminos = valid_file_format(fd)) == NULL)
		exit_failure("error\n");
	tetriminos = read_tetriminos(file_tetriminos);
	if ((map = check_2b2(tetriminos->content)) == NULL)
		map = solve(tetriminos);
	print_map(map);
	return (0);
}

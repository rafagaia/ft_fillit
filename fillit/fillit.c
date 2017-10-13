/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgaia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 13:17:42 by rgaia             #+#    #+#             */
/*   Updated: 2017/10/12 17:24:00 by rgaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	@in: single file containing up to 26 tetriminos, separated by empty line. No empty line after last tetrimino.
**  @out: stdout smallest square solution with new line. No empty line
**  @errors: 
**          1. invalid use of fillit command
**				- displays 'usage' message
**			2. invalid file format
**				- displays 'error' to stdout and exits
*/

static void		exit_error(char *str)
{
	ft_putendl(str);
	exit(EXIT_FAILURE);
}

static t_map	*init_map(void)
{
	int			i;
	int			j;
	t_map		*map;

	i = 0;
	j = 0;
	map = (t_map*)malloc(sizeof(t_map));
	map->size = 4;
	while (i < 15)
	{
		while (j < 15)
		{
			if (j < 4 && i < 4)
				(map->map)[i][j] = '.';
			else
				(map->map)[i][j] = '\0';
			j++;
		}
		j = 0;
		i++;
	}
	return (map);
}

static void		print_map(t_map *map)
{
	int			i;

	i = 0;
	while (i < (map->size) && (map->map)[i])
		ft_putendl((map->map)[i++]);
}

int				main(int argc, char **argv)
{
	int			fd;
	t_tetri		*tetriminos;
	t_map		*map;
	char		*buf;

	buf = ft_memalloc(BUF_SIZE);
	if (argc != 2)
		exit_error("usage: ./fillit source_file");
	if (!(fd = open(argv[1], O_RDONLY)))
		exit(EXIT_FAILURE);
	if (!(parse_tetrimino_file(fd, buf)))
		exit_error("error");
	tetriminos = insert_array(buf); //change initial implentation to insert from buffer rather than file
	map = init_map();
	//solve_smallest_square(tetriminos, map);
	print_map(map);
	ft_memdel((void**)&tetriminos);
	ft_memdel((void**)&buf);
	return (0);
}

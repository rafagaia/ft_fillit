/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgaia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 16:37:15 by rgaia             #+#    #+#             */
/*   Updated: 2017/11/30 09:51:39 by rgaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** This file deals with ins and outs of all map-related functions:
** init_map,  print_map, free_map, place_tetrimino
*/

t_map		*init_map(int size)
{
	int		row;
	int		col;
	t_map	*map;

	row = 0;
	map = ft_memalloc(sizeof(t_map));
	map->size = size;
	map->grid = ft_memalloc(sizeof(char*) * size);
	while (row < map->size)
	{
		col = 0;
		(map->grid)[row] = ft_strnew(map->size);
		while (col < map->size)
			(map->grid)[row][col++] = CHR_FIELD;
		row++;
	}
	return (map);
}

void		print_map(t_map *map)
{
	int		i;
	char	**grid;

	i = map->size;
	grid = map->grid;
	while (i--)
		ft_putendl(*grid++);
}

void		map_delete(t_map *map)
{
	ft_memdel((void**)(map->grid));
	ft_memdel((void**)&map);
}

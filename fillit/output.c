/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgaia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 16:37:15 by rgaia             #+#    #+#             */
/*   Updated: 2017/11/25 16:06:59 by rgaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** This file deals with ins and outs of all map-related functions:
** init_map,  print_map, free_map, place_tetrimino
*/

t_map	*init_map(int size)
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

/*
** TODO: need to make sure we're printing the map with tetrimino's letters
**		one solution: go through tetrimino list once more, and create a new map
**      by re-inserting them based on their stored t_point point structre, that saves
**		the point where that tetrimino begins on the map
**		Obs: It's not effitient to do this - better way will be to insert letters to 
**			map right away as we're doing solution, and then removing by overwriting '.'. 
**			and checking if it's available spot by checking if it IS '.'
*/
void	print_map(t_map *map)
{
	int		i;
	char	**grid;

	i = map->size;
	grid = map->grid;
	while (i--)
		ft_putendl(*grid++);
}

void	map_delete(t_map *map)
{
	ft_memdel((void**)(map->grid));
	ft_memdel((void**)&map);
}

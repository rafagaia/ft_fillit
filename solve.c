/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgaia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 02:32:20 by rgaia             #+#    #+#             */
/*   Updated: 2017/12/02 19:35:21 by rgaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_point			*point_new(int row, int col)
{
	t_point		*new;

	new = ft_memalloc(sizeof(t_point));
	new->row = row;
	new->col = col;
	return (new);
}

/*
** Checks if a tetrimino will fit starting at a point in the map
** tmp == -1 : special case for map_size 3
** tmp > 0 : cases for map_size > 4
** tmp == 0: offset complete -> proceed as if map_size == 4
**			condition needed to keep going through piece
**	TODO: add case for verify_check_fit when a piece meets BOTH
**			following conditions:
**			1) positive length >= 2
**			2) ft_abs(negative length) >= 2
**	Currently works only if either is met, not both
**	e.g.: ..##
**		  .##.
*/

int				check_fit(t_piece *tetri, t_point *point, t_map *map)
{
	int			size;
	static int	tmp[2];
	char		*piece;
	char		**grid;

	piece = tetri->piece;
	size = map->size;
	grid = map->grid;
	if (verify_check_fit(tetri, point, size) == 0)
		return (0);
	while (*piece && point->row < size)
	{
		if (tmp[0] == 0)
		{
			check_reset(point, size);
			if (verify_grid_set_tmp(piece, point, map, &tmp[0]) == 0)
				break ;
			increment_col_piece(point, &piece);
		}
		else if (tmp[0] == -1)
			increment_piece(&piece, &tmp[0]);
		else
			offset_column(point, &tmp[0], size);
	}
	return (check_fit_return(piece, point));
}

/*
** Since place_tetrimino and remove_tetrimino are same implementation,
** with difference that the first inserts a '#' at locations, and second
** inserts a '.', we insert a dot to remove tetrimino, and insert a # to
** place tetrimino.
*/

void			io_tet(char i_r, char *piece, t_point *point, t_map *map)
{
	int			tmp;
	int			i;

	tmp = 0;
	while (*piece)
	{
		if (tmp == 0)
		{
			check_reset(point, map->size);
			if (*piece == CHR_PIECE && point->row < map->size)
			{
				i = (point->col == -1 ? 1 : 0);
				if (*piece == CHR_PIECE && *(piece + 1) == CHR_FIELD)
					tmp = (map->size) - TET_SIZE;
				(i_r != CHR_FIELD ? map->grid[point->row][point->col + i] = i_r
				: (map->grid[point->row][point->col + i] = CHR_FIELD));
			}
			increment_col_piece(point, &piece);
		}
		else if (tmp == -1)
			increment_piece(&piece, &tmp);
		else
			offset_column(point, &tmp, map->size);
	}
	ft_memdel((void**)&point);
}

int				solve_recursive(t_list *tetriminos, t_map *map)
{
	t_piece		*piece;
	int			row;
	int			col;

	if (tetriminos->content == NULL)
		return (1);
	piece = (t_piece *)(tetriminos->content);
	row = -1;
	while ((++row <= ((map->size == 3 ? (map->size + 1) : (map->size))
			- piece->height)))
	{
		col = -1;
		while ((++col <= ((map->size == 3 ? (map->size + 1) : (map->size))
			- piece->length)))
		{
			if (check_fit(piece, point_new(row, col), map))
			{
				io_tet(piece->letter, piece->piece, point_new(row, col), map);
				if (solve_recursive(tetriminos->next, map))
					return (1);
				io_tet(CHR_FIELD, piece->piece, point_new(row, col), map);
			}
		}
	}
	return (0);
}

/*
** go through recursive backtracking call as many times as necessary until we
** find a solution. If we do not find a solution,
** try again with a map size incremented by 1.
** before calling again recursive backtracking function,
** delete previously used map, and
** create a new one of size++. Do this way for now, but later have a maximum
** size map already initiated at init_map, yet filled only up to the necessary
** amount, the rest of indexes filled with NULLs so at increment_size we
** may overwrite back to '.'  with an additional index
*/

t_map			*solve(t_list *tetriminos)
{
	t_map		*map;
	int			map_size;

	map_size = 3;
	while ((map_size * map_size) < (g_num_tetriminos * TET_SIZE))
		map_size++;
	map = init_map(map_size);
	while (!solve_recursive(tetriminos, map))
	{
		map_size++;
		map_delete(map);
		map = init_map(map_size);
	}
	return (map);
}

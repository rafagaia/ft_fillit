/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgaia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 02:32:20 by rgaia             #+#    #+#             */
/*   Updated: 2017/11/27 11:53:09 by rgaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"


t_point		*point_new(int row, int col)
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
** tmp == 0: offset complete, or map_size == 4
**			condition needed to keep going through piece 
*/
int		check_fit(char *piece, t_point *point, char **grid, int size)
{
	int		row;
	int		col;
	int		tmp;

	tmp = 0;
	row = point->row;
	col = point->col;
	while (*piece && row < size)
	{
		if (tmp == 0)
		{
			check_reset_column(&col, &row, size);
			
			printf("piece: %c\n", *piece);
			if (*piece == CHR_PIECE)
			{
				if (col == -1)
					col = 0;
				if (*piece == CHR_PIECE  && *(piece + 1) == CHR_FIELD)
					tmp = size - TET_SIZE;
				if (grid[row][col] != CHR_FIELD)
					break;
				grid[row][col] = '@';
			}
			increment_col_piece(&col, &piece);
		}
		else if (tmp == -1)
			increment_piece(&piece, &tmp);
		else
			offset_column(&col, &row, &tmp, size);
	}
	ft_memdel((void**)&point);
	if (*piece != '\0')
		return (0);
	return (1);
}

/*
** Since place_tetrimino and remove_tetrimino are same implementation, 
** with difference that the first inserts a '#' at locations, and second
** inserts a '.', we insert a dot to remove tetrimino, and insert a # to
** place tetrimino.
*/
void	io_tetrimino(char i_r, char *piece, t_point *point, t_map *map)
{
	int		row;
	int		col;
	int		tmp;
	char	**grid;

	tmp = 0;
	grid = map->grid;
	row = point->row;
	col = point->col;
	while (*piece)
	{
		if (tmp == 0)
		{
			check_reset_column(&col, &row, map->size);
			if (*piece == CHR_PIECE)
			{
				if (*piece == CHR_PIECE  && *(piece + 1) == CHR_FIELD)
					tmp = (map->size) - TET_SIZE;
				(i_r != CHR_FIELD ? grid[row][col] = i_r : 
				 (grid[row][col] = CHR_FIELD));
			}
			increment_col_piece(&col, &piece);
		}
		else if (tmp == -1)
			increment_piece(&piece, &tmp);
		else
			offset_column(&col, &row, &tmp, map->size);
	}
	ft_memdel((void**)&point);
}

int		solve_recursive(t_list *tetriminos, t_map *map)
{
	t_piece	*piece;
	int		row;
	int		col;

	if (tetriminos->content == NULL)
	{
		//puts("returning 1\n");	
		return (1);
	}
	piece = (t_piece *)(tetriminos->content);
	row = -1;
	while ((++row <= ((map->size == 3 ? (map->size + 1) : (map->size)) 
		- piece->height)))
	{
		col = -1;
		while ((++col <= ((map->size == 3 ? (map->size + 1) : (map->size)) 
			- piece->length)))
		{
			if (check_fit(piece->piece, point_new(row, col), map->grid, map->size))
			{
				io_tetrimino(piece->letter, piece->piece, point_new(row, col), map);
			//	print_map(map);
			//	ft_putchar('\n');
				if (solve_recursive(tetriminos->next, map))
					return (1);
				io_tetrimino(CHR_FIELD, piece->piece, point_new(row, col), map);
			}
		}
	}
//	puts("returning 0\n");
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
t_map	*solve(t_list *tetriminos)
{
	t_map	*map;
	int		map_size;

	map_size = 4;
	while ((map_size * map_size) < (g_num_tetriminos * TET_SIZE))
		map_size++;
	map = init_map(map_size);
	while (!solve_recursive(tetriminos, map))
	{
		//puts("Creating new map\n");
		map_size++;
		map_delete(map);
		map = init_map(map_size);
	}
	return (map);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgaia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 14:06:32 by rgaia             #+#    #+#             */
/*   Updated: 2017/12/02 16:10:16 by rgaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		verify_grid_set_tmp(char *piece, t_point *point, t_map *map,
							int *tmp)
{
	if (*piece == CHR_PIECE && point->row < map->size)
	{
		tmp[1] = (point->col == -1 ? 1 : 0);
		if ((map->grid)[point->row][point->col + tmp[1]] != CHR_FIELD)
			return (0);
		if (*piece == CHR_PIECE && *(piece + 1) == CHR_FIELD)
			tmp[0] = map->size - TET_SIZE;
	}
	return (1);
}

void	check_reset(t_point *point, int size)
{
	if (point->col == size)
	{
		point->col = -1;
		point->row++;
	}
}

void	offset_column(t_point *point, int *tmp, int size)
{
	while (*tmp)
	{
		check_reset(point, size);
		point->col++;
		*tmp = *tmp - 1;
	}
}

void	increment_piece(char **piece, int *tmp)
{
	*tmp = 0;
	*piece = *piece + 1;
}

void	increment_col_piece(t_point *point, char **piece)
{
	point->col++;
	*piece = *piece + 1;
}

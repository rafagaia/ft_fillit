/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgaia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 14:06:32 by rgaia             #+#    #+#             */
/*   Updated: 2017/11/27 09:40:51 by rgaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	check_reset_column(int *col, int *row, int size)
{
	if (*col == size)
	{
		*col = -1;
		*row = *row + 1;
	}
}

void	offset_column(int *col, int *row, int *tmp, int size)
{
	while (*tmp)
	{
		check_reset_column(col, row, size);
		*col = *col + 1;
		*tmp = *tmp - 1;
	}
}

void	increment_piece(char **piece, int *tmp)
{
	*tmp = 0;
	*piece = *piece + 1;
}

void	increment_col_piece(int *col, char **piece)
{
	*col = *col + 1;
	*piece = *piece + 1;
}

void	set_row_col(int row_val, int col_val, t_point *point)
{
	point->row = row_val;
	point->col = col_val;
}

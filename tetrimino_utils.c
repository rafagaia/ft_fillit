/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimino_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgaia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 01:23:45 by rgaia             #+#    #+#             */
/*   Updated: 2017/12/05 18:52:44 by eguajard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** solve.c check_fit utility to reduce number of lines in function
*/

int				check_fit_return(char *piece, t_point *point)
{
	ft_memdel((void**)&point);
	if (*piece != '\0')
		return (0);
	return (1);
}

/*
** solve.c utility function to check if it's a good condition for a tetrimino
** piece to be placed in the map. Should ideally be made in the solver
** recursive function but we ran out of space. Should refactor
** it at a later point (not priority). Would also be best to place this in
** a new solve_utils file, but the current one already has 5 functions.
*/

int				verify_check_fit(t_piece *tetri, t_point *point, int size)
{
	if (point->row >= size || point->col >= size)
		return (0);
	else if ((tetri->length < 0) && (point->col < (ft_abs(tetri->length) - 1)))
		return (0);
	else if ((point->col > (size - tetri->length)) ||
		(point->row > (size - tetri->height)))
		return (0);
	return (1);
}

/*
** Returns a pointer to the the first string that contains c
** from the string array strs, or null if not found
*/

static char		**str_contains(char **strs, char c)
{
	char		**ret;
	char		*str;

	ret = strs;
	while (*ret)
	{
		str = *ret;
		while (*str)
		{
			if (*str++ == c)
				return (ret);
		}
		ret++;
	}
	return (NULL);
}

/*
** Checks if tetrimino is of type:
** ..#.		.#..
** ..#. or  ##..
** .##.		.#..
*/

int				check_negative_length(char **t_lines)
{
	int			curr_len;
	int			first_len;
	char		*end_dot;
	char		*curr;
	char		**lines;

	lines = str_contains(t_lines, CHR_PIECE);
	curr = *lines++;
	end_dot = ft_strchr(curr, CHR_PIECE);
	first_len = 0;
	while (curr < end_dot && ++first_len)
		curr++;
	while (*lines)
	{
		curr = *lines++;
		if ((end_dot = ft_strchr(curr, CHR_PIECE)) == NULL)
			return (1);
		curr_len = 0;
		while (curr < end_dot && ++curr_len)
			curr++;
		if (curr_len < first_len)
			return (-1);
	}
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgaia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 13:18:31 by rgaia             #+#    #+#             */
/*   Updated: 2017/10/17 19:51:19 by rgaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** @in: a possible tetrimino, a string of size 20
** @out: 1 if a valid match, 0 otherwise
** checks str by comparison to all 19 hard coded tetrimino pieces
*/

static int	hash_count(char *t)
{
	int count;

	count = 0;
	while (*t)
	{
		if (*t++ == '#')
			count++;
	}
	if (count != 4)
		return (0);
	return (1);
}

static int	isvalid_tetrimino(char	*tetrimino)
{
	char	**hardcoded;

	if(!hash_count(tetrimino))
		return (0);
	tetrimino = reduce_tetrimino(tetrimino);
	hardcoded = valid_tetriminos();
	while (*hardcoded)
	{
		if (ft_strcmp(tetrimino, *hardcoded++) == 0)
			return (1);
	}
	return (0);
}

static t_tetri	*get_next_tetrimino(char c, char	*str)
{
	t_tetri	*t;

	t = (t_tetri *)malloc(sizeof(t_tetri));
	t->letter = c;
	t->str_tetri = ft_strdup(str);
	ft_strdel(&str);
	return (t);
}

/*
**	@in: buffer with valid file format and characters with min 1, max 26 possible tetriminos
**	@out: tetrimino array of type t_tetri
**			- contains valid tetrimino with unique capital case letter
**	@error: invalid tetrimino
**			- returns NULL
*/
t_tetri			**insert_array(char *buf)
{
	int		i;
	char	letter;
	char	*str;
	t_tetri	**tetriminos;

	i = 0;
	letter = 'A';
	if (!(tetriminos = ft_memalloc(sizeof(t_tetri *) * 26)))
		return (NULL);
	while (*buf)
	{
		str = ft_strnew(20);
		str = ft_strncpy(str, buf, 20);
		if (isvalid_tetrimino(str))
		{
			tetriminos[i] = get_next_tetrimino(letter++, str);
			i++;
		}
		else
			return (NULL);
		buf = buf + 21;
	}
	return (tetriminos);
}

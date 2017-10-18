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

static t_tetri	*get_next_tetrimino(char *buf, char c, t_tetri *t)
{
	int		i;
	char	*str;
	char	**valids;

	i = 0;
	valids = valid_tetriminos();
	if (!(buf[0])) //check if reached end of buffer
		return (NULL);
	else if (buf[0] == '\n')
		buf++;
	str = ft_strnew(20);
	str = ft_strncpy(str, buf, 20);
	str = reduce_tetrimino(str);
	ft_putendl("PASSES REDUCE_TETRIMINO");
	ft_putstr(str);
	t->letter = c;
	t->str_tetri = ft_strdup(str);
	ft_strdel(&str);
	return (t);
}

static int	isvalid_tetrimino(char *tetrimino, char **hardcoded)
{
	while (*hardcoded)
	{
		if (ft_strcmp(tetrimino, *hardcoded++) == 0)
			return (1);
	}
	return (0);
}

/*
**	@in: buffer with valid file format and characters with min 1, max 26 possible tetriminos
**	@out: tetrimino array of type t_tetri
**			- contains valid tetrimino with unique capital case letter
**	@error: invalid tetrimino
**			- returns NULL
*/
t_tetri			*insert_array(char *buf)
{
	char	letter;
	t_tetri	*tetrimino;
	t_tetri	*out_tetrimino;
	char	**hardcoded;

	letter = 'A';
	if (!(tetrimino = ft_memalloc(sizeof(t_tetri) * 26)))
		return (NULL);
	out_tetrimino = tetrimino;
	hardcoded = valid_tetriminos();
	ft_putendl("INITS VALID_TETRIMINOS");
	while ((tetrimino = get_next_tetrimino(buf, letter++, tetrimino)))
	{
		if (isvalid_tetrimino(tetrimino->str_tetri, hardcoded))
		{
			tetrimino++;
			buf = buf + 21;
			ft_putendl("REACHES IS_VALIDTETRIMINO");
		}
		else
			return (NULL);
	}
	return (out_tetrimino);
}

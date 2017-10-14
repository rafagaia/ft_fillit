/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgaia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 13:18:31 by rgaia             #+#    #+#             */
/*   Updated: 2017/10/13 17:22:09 by rgaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** @in: a possible tetrimino, a string of size 20
** @out: 1 if a valid match, 0 otherwise
** checks str by comparison to all 19 hard coded tetrimino pieces
*/
int				isvalid_tetrimino(char *str, char **hardcoded)
{
	while (*hardcoded)
	{
		if (ft_strcmp(str, *hardcoded++) == 0)
			return (1);
	}
	return (0);
}

static t_tetri	get_next_tetrimino(char *buf, char c, t_tetri *t)
{
	char	*str;
	int		i;
	
	i = 0;
	if (!(buf[0])) //check if reached end of buffer
		return (0);
	else if (buf[0] == '\n')
		buf++;
	str = ft_strnew(20);
	str = ft_strncpy(str, buf, 20);
	if (!(isvalid_tetrimino(str)))
	{
		ft_strdel(&str);
		return (0);
	}
	t->letter = c;
	t->str_tetri = ft_strdup(t->str_tetri, str);
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
t_tetri			*insert_array(char *buf)
{
	int		i;
	char	letter;
	t_tetri	*tetrimino;
	t_tetri	*out_tetrimino;

	i = 0;
	letter = 'A';
	if (!(tetrimino = ft_memalloc(sizeof(t_tetri) * 26)))
		return (NULL);
	out_tetrimino = tetrimino;
	while (tetrimino = get_next_tetrimino(buf, letter, tetrimino))
	{
		tetrimino++;
		buf = buf + 21;
	}
	return (out_tetrimino);
}

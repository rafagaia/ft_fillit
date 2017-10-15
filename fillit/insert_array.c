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

static char    **ft_darraynew(int i, int j)
{
    int n;
    char **darray;

    n = 0;
    darray = (char **)malloc(sizeof(char*) * i);
    while (n < i)
    {
        darray[n++] = (char *)malloc(sizeof(char) * j);
    }
    return (darray);
}

static char	**valid_tetriminos(void)
//run through and strcmp everything
{
    char    **valids;

    valids = ft_darraynew(19, 14);
    ft_strcpy(valids[0], "####");
    ft_strcpy(valids[1], "##..##");
    ft_strcpy(valids[2], "#...#...#...#");
    ft_strcpy(valids[3], "##..#...#");
    ft_strcpy(valids[4], "#...##..#");
    ft_strcpy(valids[5], "#...#...##");
    ft_strcpy(valids[6], "#...#..##");
    ft_strcpy(valids[7], "##...#...#");
    ft_strcpy(valids[8], "#...###");
    ft_strcpy(valids[9], "#.###");
    ft_strcpy(valids[10], "###.#");
    ft_strcpy(valids[11], "###...#");
    ft_strcpy(valids[12], "##.##");
    ft_strcpy(valids[13], "#..##..#");
    ft_strcpy(valids[14], "###..#");
    ft_strcpy(valids[15], "#..##...#");
    ft_strcpy(valids[16], "###..#");
    ft_strcpy(valids[17], "#..###");
    ft_strcpy(valids[18], "##...##");
    valids[19] = NULL;
    return (valids);
}

static char	*reduce_tetrimino(char *t)
{
    int     count;
    char    *reduced;
    char    *reducedcpy;

    count = 0;
    t = strchr(t, '#');
    reduced = (char *)malloc(sizeof(char) * 14);
    reducedcpy = reduced;
    while (*t && count < 4)
    {
        if (*t == '\n')
            t++;
        if (*t == '#')
            count++;
        *reduced++ = *t++;
    }
    *reduced = '\0';
    return (reducedcpy);
}

static int	validate_tetriminos(char *t, char **valids)
{
    while (*valids)
    {
        if (ft_strcmp(t, *valids++) == 0)
            return (1);
    }
    return (0); //not a valid tetrimino
}

static t_tetri	get_next_tetrimino(char *buf, char c, t_tetri *t)
{
	int		i;
	char	*str;
	char	**valids;

	i = 0;
	valids = valid_tetriminos();
	if (!(buf[0])) //check if reached end of buffer
		return (0);
	else if (buf[0] == '\n')
		buf++;
	str = ft_strnew(20);
	str = ft_strncpy(str, buf, 20);
	str = reduce_tetrimino(str);
	if (validate_tetriminos(str, valids) == 0)
	{
		ft_strdel(&str);
		return (0);
	}
	t->letter = c; //?
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
	t_tetri	*hardcoded; //

	i = 0;
	letter = 'A';
	if (!(tetrimino = ft_memalloc(sizeof(t_tetri) * 26)))
		return (NULL);
	out_tetrimino = tetrimino;
	while (tetrimino = get_next_tetrimino(buf, letter, tetrimino))
	{
		tetrimino++;
		letter++;
		buf = buf + 21;
	}
	return (out_tetrimino);
}

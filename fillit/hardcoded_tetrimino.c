/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hardcoded_tetrimino.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgaia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 17:46:07 by rgaia             #+#    #+#             */
/*   Updated: 2017/10/14 00:08:42 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "fillit.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
/*
	Stores all valid tetriminos in an array.
	Uses string compare to check if the tetrimino passed is valid.
*/

static char **validate_tetriminos(char *t, char **valids)
{
    while (*valids)
    {
        if (ft_strcmp(t, *valids++) == 0)
            return (1);
    }
    return (0); //not a valid tetrimino
}

static char	**valid_tetriminos(char *t)
//run through and strcmp everything
{
    char    **valids;

    valids = ft_darraynew(19, 14);
    valids[1] = "####";
    valids[2] = "##..##";
    valids[3] = "#...#...#...#";
    valids[4] = "##..#...#";
    valids[5] = "#...##..#"
    valids[6] = "#...#...##";
    valids[7] = "#...#..##";
    valids[8] = "##...#...#";
    valids[9] = "#...###";
    valids[10] = "#.###";
    valids[11] = "###.#";
    valids[12] = "###...#";
    valids[13] = "##.##";
    valids[14] = "#..##..#";
    valids[15] = "###..#";
    valids[16] = "#..##...#";
    valids[17] = "###..#";
    valids[18] = "#..###";
    valids[19] = "##...##";
    return (valids);
}

char	*reduce_tetrimino(char *t)
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

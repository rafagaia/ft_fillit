/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 14:19:26 by sadamant          #+#    #+#             */
/*   Updated: 2017/10/05 14:19:28 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int         validate_tetrimino(char *tetrimino)
{
    int     i;

    i = 0;
    if (tetrimino[i] == '#' || tetrimino[i] == '.' || tetrimino[i] == '\n')
    {
        i++;
    }
    else
        return (-1);
    return (0);
}

char        **insert_array(int fd)
{
    int     i;
    char    *tetrimino;
    char    **tetriminos;

    i = 0;
    tetrimino = ft_strnew(19);
    tetriminos = ft_darraynew(26, 20);
    read(fd, tetrimino, 19);
    if (validate_tetrimino(tetrimino) == 0)
    {
        ft_strcpy(tetriminos[i++], tetrimino);
    }
    else
    {
        // exit, not a valid file!
    }
    while (read(fd, tetrimino, 2) == 2)
    {
        read(fd, tetrimino, 19);
        if (validate_tetrimino(tetrimino) == 0)
            ft_strcpy(tetriminos[i++], tetrimino);
        else
        ;
            // exit, not a valid file!
    }
    return (tetriminos);
}

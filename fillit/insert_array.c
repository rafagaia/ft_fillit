/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgaia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 13:18:31 by rgaia             #+#    #+#             */
/*   Updated: 2017/10/12 15:30:31 by rgaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetri		*insert_array(char *buf)
{
	
}




/*char		**insert_array(int fd)
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
}*/

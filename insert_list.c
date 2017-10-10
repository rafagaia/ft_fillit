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

char        **insert_array(int fd)
{
    int     i;
    char    *tetrimino;
    char    **tetriminos;

    i = 0;
    tetrimino = ft_strnew(19);
    tetriminos = ft_darraynew(26, 20);
    read(fd, tetrimino, 19);
    ft_strcpy(tetriminos[i++], tetrimino);
    while (read(fd, tetrimino, 2) == 2)
    {
        read(fd, tetrimino, 19);
        ft_strcpy(tetriminos[i++], tetrimino);
    }
    return (tetriminos);
}

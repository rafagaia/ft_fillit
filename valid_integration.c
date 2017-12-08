/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_integration.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguajard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 21:16:44 by eguajard          #+#    #+#             */
/*   Updated: 2017/12/01 16:46:49 by rgaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			valid_characters(char **file_tet, int elem, int i, int count)
{
	while (file_tet[elem][i] != '\0')
	{
		if ((count % 5 == 0) && count != 20 && file_tet[elem][i] == '\n')
		{
			i++;
			count++;
		}
		else if ((file_tet[elem][i] == '#' || file_tet[elem][i] == '.'))
		{
			i++;
			count++;
		}
		else if (count == 20)
		{
			count = 1;
			elem++;
			i = 0;
			if (file_tet[elem] == '\0')
				return (1);
		}
		else
			return (0);
	}
	return (0);
}

/*
** Verify only 4 hash
*/

int			if_valid_hash_num(char *file_buf, int piece)
{
	int		place;
	int		count;

	count = 0;
	place = 0;
	while (file_buf[piece + place] && place < 21)
	{
		if (file_buf[piece + place] == '#')
			count++;
		if ((file_buf[piece + place] == '\n' &&
			file_buf[piece + place + 1] == '\n')
			|| (file_buf[piece + place] == '\n' &&
			file_buf[piece + place + 1] == '\0'))
			break ;
		place++;
	}
	if (count != 4)
		return (0);
	return (1);
}

int			if_new_line_end(char *file_buf, int i)
{
	if ((file_buf[i - 1] == '\n') && (file_buf[i - 2] == '\n'))
	{
		return (0);
	}
	else
		return (1);
}

int			valid_tetri(char *file_buf, int i)
{
	while (file_buf[i])
	{
		if (!if_valid_hash_num(file_buf, i))
			return (0);
		if ((if_linea_sqr(file_buf, i)) == 1
				|| if_l(file_buf, i)
				|| if_t(file_buf, i)
				|| if_li(file_buf, i)
				|| if_s_si(file_buf, i))
		{
			i += 21;
			continue ;
		}
		return (0);
	}
	return (if_new_line_end(file_buf, i));
}

/*
** Receives a file descriptor and saves file content into a buffer.
** Checks if file isn't too small or too big.
** Copies each 4x4 block from file into a char pointer,
** and stores into a double char pointer
** If the piece string obtained from file has length smaller than TET_AREA,
** means improper
** formatting - deallocate file_tetriminos and return NULL
** TODO: free_file_tetriminos
*/

char		**valid_file_format(int fd)
{
	char	*file_buf;
	char	**file_tetriminos;

	if ((file_buf = read_file(fd)) == NULL)
		return ((char**)0);
	if (valid_tetri(file_buf, 0) == 0)
		return (NULL);
	if ((file_tetriminos = split_tetriminos(file_buf, 0)) == NULL)
		return ((char**)0);
	if (valid_characters(file_tetriminos, 0, 0, 1) == 0)
	{
		return ((char**)0);
	}
	return (file_tetriminos);
}

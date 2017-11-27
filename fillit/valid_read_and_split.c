/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_read_and_split.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguajard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 21:17:02 by eguajard          #+#    #+#             */
/*   Updated: 2017/11/24 16:53:35 by rgaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Calculates the number of Tetriminos a file is expected to have,
** given it's length
*/

int			get_num_tetriminos(size_t len)
{
	int		num;

	num = (((int)len + 1) / (TET_AREA + 1));
	return (num);
}

/*
** Does some preliminary file validation after reading into buffer to make sure
** it's not too small (less than a single tetrimino), or not too large
** (larger than MAX_TET (max tetriminos))
*/

char		*read_file(int fd)
{
	int		bytes_read;
	char	*file_buf;

	file_buf = ft_strnew(BUF_SIZE);
	bytes_read = read(fd, file_buf, BUF_SIZE);
	close(fd);
	if (bytes_read > MAX_F_LEN || bytes_read < TET_AREA)
	{
		ft_strdel(&file_buf);
		return (NULL);
	}
	if (!((ft_strlen(file_buf) == 20) ||
		((ft_strlen(file_buf) - 20) % 21 == 0)))
		return (0);
	file_buf[bytes_read] = '\0';
	return (file_buf);
}

/*
** At this point, we know file_buf isn't too big or too small
** (j): variable keeps index of new lines that splits tetriminos.
**		if we don't access here and check if it's a new line or other character,
**		the character at j's index will be skipped and will not be
** accessible again from the **file_tetriminos
*/

char		**split_tetriminos(char *file_buf)
{
	int		i;
	int		j;
	int		expected_num_tetriminos;
	char	*piece;
	char	**file_tetriminos;

	i = 0;
	j = 0;
	expected_num_tetriminos = get_num_tetriminos(ft_strlen(file_buf));
	g_num_tetriminos = expected_num_tetriminos;
	file_tetriminos = malloc(sizeof(char*) * expected_num_tetriminos + 1);
	file_tetriminos[expected_num_tetriminos] = (char*)0;
	while (i < expected_num_tetriminos)
	{
		piece = ft_strndup((file_buf + (j++) + (i * TET_AREA)), TET_AREA);
		if (ft_strlen(piece) != TET_AREA)
		{
			ft_strdel(&piece);
			while (i--)
				ft_strdel(&file_tetriminos[i]);
			ft_memdel((void**)file_tetriminos);
			return ((char **)0);
		}
		file_tetriminos[i++] = piece;
	}
	return (file_tetriminos);
}

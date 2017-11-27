/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_shape.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguajard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 21:16:21 by eguajard          #+#    #+#             */
/*   Updated: 2017/11/22 21:16:24 by eguajard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		if_linea_sqr(char *file_buf, int i)
{
	int j;

	j = 0;
	while (file_buf[i + j] && j < 21)
	{
		if (file_buf[i + j] == '#' && file_buf[i + j + 1] == '#' &&
				file_buf[i + j + 2] == '#' && file_buf[i + j + 3] == '#')
			return (1);
		else if (file_buf[i + j] == '#' && file_buf[i + j + 5] == '#' &&
				file_buf[i + j + 10] == '#' && file_buf[i + j + 15] == '#')
			return (1);
		else if (file_buf[i + j] == '#' && file_buf[i + j + 1] == '#' &&
				file_buf[i + j + 5] == '#' && file_buf[i + j + 6] == '#')
			return (1);
		j++;
	}
	return (0);
}

int		if_l(char *file_buf, int i)
{
	int j;

	j = 0;
	while (file_buf[i + j] && j < 21)
	{
		if (file_buf[i + j] == '#' && file_buf[i + j + 1] == '#' &&
				file_buf[i + j + 2] == '#' && file_buf[i + j + 7] == '#')
			return (1);
		if (file_buf[i + j] == '#' && file_buf[i + j + 5] == '#' &&
				file_buf[i + j + 9] == '#' && file_buf[i + j + 10] == '#')
			return (1);
		if (file_buf[i + j] == '#' && file_buf[i + j + 5] == '#' &&
				file_buf[i + j + 6] == '#' && file_buf[i + j + 7] == '#')
			return (1);
		if (file_buf[i + j] == '#' && file_buf[i + j + 1] == '#' &&
				file_buf[i + j + 5] == '#' && file_buf[i + j + 10] == '#')
			return (1);
		j++;
	}
	return (0);
}

int		if_t(char *file_buf, int i)
{
	int j;

	j = 0;
	while (file_buf[i + j] && j < 21)
	{
		if (file_buf[i + j] == '#' && file_buf[i + j + 1] == '#' &&
				file_buf[i + j + 2] == '#' && file_buf[i + j + 6] == '#')
			return (1);
		if (file_buf[i + j] == '#' && file_buf[i + j + 4] == '#' &&
				file_buf[i + j + 5] == '#' && file_buf[i + j + 10] == '#')
			return (1);
		if (file_buf[i + j] == '#' && file_buf[i + j + 4] == '#' &&
				file_buf[i + j + 5] == '#' && file_buf[i + j + 6] == '#')
			return (1);
		if (file_buf[i + j] == '#' && file_buf[i + j + 5] == '#' &&
				file_buf[i + j + 6] == '#' && file_buf[i + j + 10] == '#')
			return (1);
		j++;
	}
	return (0);
}

int		if_li(char *file_buf, int i)
{
	int j;

	j = 0;
	while (file_buf[i + j] && j < 21)
	{
		if (file_buf[i + j] == '#' && file_buf[i + j + 1] == '#' &&
				file_buf[i + j + 2] == '#' && file_buf[i + j + 5] == '#')
			return (1);
		if (file_buf[i + j] == '#' && file_buf[i + j + 1] == '#' &&
				file_buf[i + j + 6] == '#' && file_buf[i + j + 11] == '#')
			return (1);
		if (file_buf[i + j] == '#' && file_buf[i + j + 3] == '#' &&
				file_buf[i + j + 4] == '#' && file_buf[i + j + 5] == '#')
			return (1);
		if (file_buf[i + j] == '#' && file_buf[i + j + 5] == '#' &&
				file_buf[i + j + 10] == '#' && file_buf[i + j + 11] == '#')
			return (1);
		j++;
	}
	return (0);
}

int		if_s_si(char *file_buf, int i)
{
	int j;

	j = 0;
	while (file_buf[i + j] && j < 21)
	{
		if (file_buf[i + j] == '#' && file_buf[i + j + 1] == '#' &&
			file_buf[i + j + 4] == '#' && file_buf[i + j + 5] == '#')
			return (1);
		if (file_buf[i + j] == '#' && file_buf[i + j + 5] == '#' &&
			file_buf[i + j + 6] == '#' && file_buf[i + j + 11] == '#')
			return (1);
		if (file_buf[i + j] == '#' && file_buf[i + j + 1] == '#' &&
			file_buf[i + j + 6] == '#' && file_buf[i + j + 7] == '#')
			return (1);
		if (file_buf[i + j] == '#' && file_buf[i + j + 4] == '#' &&
			file_buf[i + j + 5] == '#' && file_buf[i + j + 9] == '#')
			return (1);
		j++;
	}
	return (0);
}

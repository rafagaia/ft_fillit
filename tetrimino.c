/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimino.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgaia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 16:11:48 by rgaia             #+#    #+#             */
/*   Updated: 2017/12/05 18:53:06 by eguajard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** This file takes @in char** containing at each index, a pointer to a valid
** tetrimino string of len TET_AREA.
** It inserts Reduced Tetrimino piece as string into t_piece struct, and inits
** the other variables part of the t_piece struct.
** @out: It then creates a Singly Linked List and Links all Tetrimino t_piece
** Structs,  and returns back to main function a pointer to the HEAD of the
** Linked List.
*/

static int		get_tet_h(char **split_red_tet)
{
	int			height;

	height = 0;
	while (*split_red_tet)
	{
		height++;
		split_red_tet++;
	}
	return (height);
}

static int		get_tet_l(char **split_red_tet, char **t_lines)
{
	int			max_len;
	int			temp;
	int			neg;

	temp = 0;
	neg = check_negative_length(t_lines);
	while (*t_lines)
		ft_strdel(t_lines++);
	max_len = ft_strlen(*split_red_tet++);
	while (*split_red_tet)
	{
		if ((temp = ft_strlen(*split_red_tet)) > max_len)
			max_len = temp;
		split_red_tet++;
	}
	return (neg * max_len);
}

char			*reduce_tetrimino(char *str_tetrimino)
{
	int			hash_diff;
	char		*first_hash;
	char		*last_hash;
	char		*red_tetrimino;

	first_hash = ft_strchr(str_tetrimino, CHR_PIECE);
	last_hash = ft_strrchr(str_tetrimino, CHR_PIECE);
	hash_diff = last_hash - first_hash + 1;
	red_tetrimino = ft_strndup(first_hash, hash_diff);
	return (red_tetrimino);
}

t_piece			*init_tetrimino(char *str_tetrimino, char letter)
{
	char		*red_tetrimino;
	char		**t_lines;
	char		**split_red_tet;
	t_piece		*tetrimino;

	tetrimino = ft_memalloc(sizeof(t_piece));
	t_lines = ft_strsplit(str_tetrimino, '\n');
	red_tetrimino = reduce_tetrimino(str_tetrimino);
	red_tetrimino = ft_chrsub(red_tetrimino, '\n', CHR_FIELD);
	split_red_tet = ft_strsplit(red_tetrimino, '.');
	tetrimino->piece = ft_strdup(red_tetrimino);
	if (ft_strequ(red_tetrimino, "#...###") == 1)
		tetrimino->length = -2;
	else
		tetrimino->length = get_tet_l(split_red_tet, t_lines);
	tetrimino->height = get_tet_h(split_red_tet);
	tetrimino->letter = letter;
	while (*split_red_tet)
		ft_strdel(split_red_tet++);
	ft_strdel(&red_tetrimino);
	return (tetrimino);
}

t_list			*read_tetriminos(char **file_tetriminos)
{
	char		letter;
	t_list		*tetriminos;
	t_piece		*new_tetri;

	letter = 'A';
	tetriminos = NULL;
	while (*file_tetriminos)
	{
		new_tetri = init_tetrimino(*file_tetriminos++, letter++);
		ft_lstadd_back(&tetriminos, ft_lstnew(new_tetri, sizeof(t_piece)));
	}
	ft_lstadd_back(&tetriminos, ft_lstnew(NULL, 0));
	return (tetriminos);
}

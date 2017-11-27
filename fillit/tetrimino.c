/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimino.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgaia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 16:11:48 by rgaia             #+#    #+#             */
/*   Updated: 2017/11/24 14:20:03 by rgaia            ###   ########.fr       */
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

int			get_tet_h(char **split_red_tet)
{
	int height;

	height = 0;
	while (*split_red_tet)
	{
		height++;
		split_red_tet++;
	}
	return (height);
}

int			get_tet_l(char **split_red_tet)
{
	int		max_len;
	int		temp;

	max_len = 0;
	temp = 0;
	while (*split_red_tet)
	{
		if ((temp = ft_strlen(*split_red_tet)) > max_len)
			max_len = temp;
		split_red_tet++;
	}
	return (max_len);
}

char		*reduce_tetrimino(char *str_tetrimino)
{
	int		hash_diff;
	char	*first_hash;
	char	*last_hash;
	char	*red_tetrimino;

	first_hash = ft_strchr(str_tetrimino, CHR_PIECE);
	last_hash = ft_strrchr(str_tetrimino, CHR_PIECE);
	hash_diff = last_hash - first_hash + 1;
	red_tetrimino = ft_strndup(first_hash, hash_diff);
	return (red_tetrimino);
}

t_piece		*init_tetrimino(char *str_tetrimino, char letter)
{
	char		*red_tetrimino;
	char		**split_red_tet;
	t_piece		*tetrimino;

	red_tetrimino = reduce_tetrimino(str_tetrimino);
	tetrimino = ft_memalloc(sizeof(t_piece));

	red_tetrimino = ft_chrsub(red_tetrimino, '\n', CHR_FIELD);
	split_red_tet = ft_strsplit(red_tetrimino, '.');
	tetrimino->piece = ft_strdup(red_tetrimino);
	tetrimino->height = get_tet_h(split_red_tet);
	tetrimino->length = get_tet_l(split_red_tet);
	tetrimino->letter = letter;
	while (*split_red_tet)
		ft_strdel(split_red_tet++);
	ft_strdel(&red_tetrimino);
	return (tetrimino);
}

t_list		*read_tetriminos(char **file_tetriminos)
{
	char	letter;
	t_list	*tetriminos;
	t_piece	*new_tetri;

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

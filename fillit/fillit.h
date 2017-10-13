/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgaia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 17:10:14 by rgaia             #+#    #+#             */
/*   Updated: 2017/10/12 17:23:35 by rgaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FILLIT_H
# define __FILLIT_H
# define VALID_CHAR(x) (x == '.' || x == '#')
# define BUF_SIZE 546

# include <fcntl.h> //open
# include <stdlib.h>
# include <stdio.h> //DELETE before submission
# include "../libft/libft.h"

typedef struct
{
	char	letter;
	char	*tetrimino;
}			t_tetri;

typedef struct
{
	size_t		size;
	char		map[15][15];
}				t_map;


int				parse_tetrimino_file(int fd, char *buf);

t_tetri			*insert_array(int num_tetriminos, char *buf);

void			solve_smallest_square(t_tetri *tetriminos, t_map *map);

#endif

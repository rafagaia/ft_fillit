/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgaia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 16:29:53 by rgaia             #+#    #+#             */
/*   Updated: 2017/12/05 16:11:38 by rgaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft/libft.h"

# define TRUE 1
# define FALSE 0
# define CHR_FIELD '.'
# define CHR_PIECE '#'

/*
** Max 26 pieces -> 21 * 26 - 1 = Maximum bytes allowed within file
** If Buffer fills to size >= 546 -> invalid file
*/

# define MAX_TET  26
# define TET_SIZE 4
# define TET_AREA ((TET_SIZE * TET_SIZE) + TET_SIZE)
# define MAX_F_LEN (TET_AREA + 1) * MAX_TET
# define BUF_SIZE (MAX_F_LEN + 1)

int						g_num_tetriminos;

typedef	struct			s_point
{
	int					row;
	int					col;

}						t_point;

typedef struct			s_piece
{
	int					length;
	int					height;
	char				letter;
	char				*piece;
}						t_piece;

typedef struct			s_map
{
	char				**grid;
	int					size;
}						t_map;

/*
** INPUT FUNCTIONS:
**	@in: text file containing 4x4 tetrimino pieces separated by a new line
**	@out: a List comprised of Linked Piece Structures containing all variables
**  that describe a tetrimino piece
*/

/*
** valid_file_format:
** @in: file descriptor for Opened inputted file
** @out: File Characters, and Formatting is good -> returns tetrimino strings
** @error: File not good -> returns NULL
*/

char					**valid_file_format(int fd);
int						get_num_tetriminos(size_t len);
t_point					*point_new(int row, int col);

/*
** valid_shape.c
*/

int						if_linea_sqr(char *file_buf, int i);
int						if_l(char *file_buf, int i);
int						if_t(char *file_buf, int i);
int						if_li(char *file_buf, int i);
int						if_s_si(char *file_buf, int i);

/*
** valid_integration.c
*/

int						valid_characters(char **file_tet, int elem, int i,
											int count);
int						if_valid_hash_num(char *file_buf, int j);
int						if_new_line_end(char *file_buf, int i);
int						valid_tetri(char *file_buf, int i);
char					**valid_file_format(int fd);

/*
** valid_read_and_split.c
*/

int						get_num_tetriminos(size_t len);
char					*read_file(int fd);
char					**split_tetriminos(char *file_buf, int i);

/*
** read_tetriminos:
** @in: buffer containing a possibly valid tetrimino string at each index
** @out: a List of Structs containing all Tetrimino Piece required variables
** @error: if any tetrimino is invalid -> returns NULL
*/

t_list					*read_tetriminos(char **file_tetriminos);

/*
** Checks if all tetriminos are valid tetriminos
*/

int						check_tetrimino(t_list *tetrimino);
int						check_negative_length(char **t_lines);

/*
** SOLVE FUNCTIONS:
*/

/*
** solve:
** Entry function to our fill smallest square solver.
** This function will call the recursive function, and  initialize the
** map that'll be returned when a solution is found.
** If a solution is not found, we delete previously used map, create a
** new one with incremented size, and call solve_backtrack again
*/

t_map					*solve(t_list *tetriminos);
int						check_fit(t_piece *piece, t_point *point,
									t_map *map);
int						check_fit_return(char *piece, t_point *point);
void					check_reset_column(char **piece, t_point *point,
											int size);
void					check_reset(t_point *point, int size);
void					offset_column(t_point *point, int *tmp, int size);
void					increment_col_piece(t_point *point, char **piece);
void					increment_piece(char **piece, int *tmp);
int						verify_check_fit(t_piece *tetri, t_point *point,
											int size);
int						verify_grid_set_tmp(char *piece, t_point *point,
											t_map *map, int *tmp);

/*
** map_tetrimino works as place_tetrimino and remove_tetrimino:
** i_r == '.': remove_tetrimino
** i_r == '#': place_tetrimino.
** Obs: does not do error checking. Will insert character sent to i_r
*/

void					io_tet(char i_r, char *piece, t_point *point,
								t_map *map);
t_point					*point_new(int row, int col);

/*
** OUTPUT FUNCTIONS:
*/

void					print_map(t_map *map);
t_map					*init_map(int size);
void					map_delete(t_map *map);

/*
** MEMORY FREE FUNCTIONS
*/

void					free_memories(t_list *tetriminos, t_map *map);

#endif

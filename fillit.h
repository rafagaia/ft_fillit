/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgaia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 17:10:14 by rgaia             #+#    #+#             */
/*   Updated: 2017/10/04 19:11:35 by rgaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FILLIT_H
# define __FILLIT_H

# include "libft.h"
# include <fcntl.h> //open
# include <stdio.h> //DELETE before submission

typedef struct	s_map
{
	size_t		size;
	char		map[15][15];
}				t_map;

t_list	*insert_list(int fd);
#endif

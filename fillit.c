/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgaia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 17:07:51 by rgaia             #+#    #+#             */
/*   Updated: 2017/10/04 19:11:24 by rgaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	// int		i;
	int		fd;
	char	**content;
	char	**tetriminos;

	// i = 0;
	if (argc != 2)
		return (-1); //TODO: exit properly
	if (!(fd = open(argv[1], O_RDONLY)))
		return (-1); //TODO: exit properly
	tetriminos = insert_array(fd);
	printf("%s\n", tetriminos[0]);
	// while (tetriminos[i])
	// {
	// 	printf("%s\n", tetriminos[i++]);
	// }
	close(fd);
	return (0);
}

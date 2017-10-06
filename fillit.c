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
	int		fd;
	char	**content;
	t_list	*tetriminos;

	if (argc != 2)
		return (-1); //TODO: exit properly
	if (!(fd = open(argv[1], O_RDONLY)))
		return (-1); //TODO: exit properly
	tetriminos = insert_list(fd);
	// print all tetriminos in the list
	// while (tetriminos)
	// {
	// 	printf("\nthe next tetrimino\n");
	// 	ft_putstr(tetriminos->content);
	// 	tetriminos = tetriminos->next;
	// }
	close(fd);
	return (0);
}

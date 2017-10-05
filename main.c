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
#include <fcntl.h> //for open
#include <stdio.h> //DELETE before submission


int		main(int argc, char **argv)
{
	int		fd;
	t_list	*tetriminos;

	tetriminos = ft_lstnew(NULL. 0);
	if (argc != 2)
		return (-1); //TODO: exit properly
	if (!(fd = open(argv[1], O_RDONLY))
		return (-1); //TODO: exit properly
	//function to read all tetriminos and input into a linked list
	

	return (0);
}
































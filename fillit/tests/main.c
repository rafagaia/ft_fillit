/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgaia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 19:09:16 by rgaia             #+#    #+#             */
/*   Updated: 2017/10/11 19:11:59 by rgaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

void	test_exit(void)
{
	printf("entering test_exit");
	exit(EXIT_FAILURE);
	printf("should not print this");
}

int		main(void)
{
	test_exit();
	printf("returned from test_exit function");
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgaia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 08:22:53 by rgaia             #+#    #+#             */
/*   Updated: 2017/09/29 21:58:23 by rgaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		num;
	int		sign;
	char	*s;

	num = 0;
	sign = 1;
	s = (char *)str;
	while (*s == '\n' || *s == '\t' || *s == '\r'
			|| *s == '\v' || *s == '\f' || *s == ' ')
		s++;
	if (*s == '-')
		sign = -1;
	if (*s == '-' || *s == '+')
		s++;
	while (*s && ft_isdigit(*s))
		num = (num * 10) + (*s++ - '0');
	return (sign * num);
}

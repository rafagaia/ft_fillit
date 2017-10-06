/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 14:19:26 by sadamant          #+#    #+#             */
/*   Updated: 2017/10/05 14:19:28 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_list   *append_list(t_list *head, t_list *new)
{
    t_list  *cur;
    if (head->content == NULL)
        return (new);
    while (cur->next)
    {
        cur = cur->next;
    }
    cur->next = new;
    return (head);
}

t_list          *insert_list(int fd)
{
    int     i;
    t_list  *current;
    t_list  *head;
    char    **tetrimino;

    i = 0;
    head = ft_lstnew(NULL, 0);
    tetrimino = ft_newdarray(4, 4);
    while (i < 4)
    {
        read(fd, tetrimino[i], 4);
        i++;
        read(fd, tetrimino[i], 1);
    }
    current = ft_lstnew(tetrimino, sizeof(tetrimino) * 4); //not sure about size
    head = append_list(head, current);
    read(fd, tetrimino[i], 1);
    return (head);
}

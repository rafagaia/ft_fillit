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
    cur = head;
    while (cur->next)
    {
        cur = cur->next;
    }
    cur->next = new;
    return (head);
}

t_list          *insert_list(int fd)
{
    t_list  *head;
    char    *tetrimino;

    head = ft_lstnew(NULL, 0);
    tetrimino = ft_strnew(19);
    while (1)
    {
        if (tetrimino[0] == '\0')
        {
            read(fd, tetrimino, 19);
            head = append_list(head, ft_lstnew(tetrimino, ft_strlen(tetrimino)));
        }
        else if (read(fd, tetrimino, 2) == 2)
        {
            read(fd, tetrimino, 19);
            head = append_list(head, ft_lstnew(tetrimino, ft_strlen(tetrimino)));
        }
        else
            return (head);
    }
    return (head);
}

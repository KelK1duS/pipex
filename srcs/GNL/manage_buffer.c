/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_buffer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 10:54:18 by bedarenn          #+#    #+#             */
/*   Updated: 2023/11/28 17:41:51 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libgnl.h>
#include <stdlib.h>

static t_buffer	**get_static(void)
{
	static t_buffer	*b = NULL;

	return (&b);
}

t_buffer	*get_buffer(int fd)
{
	t_buffer	**s;

	s = get_static();
	if (!*s)
	{
		*s = new_buffer(fd);
		if (!s)
			return (NULL);
	}
	if ((*s)->fd == fd)
		return (*s);
	while ((*s)->next && (*s)->next->fd != fd)
		*s = (*s)->next;
	if (!(*s)->next)
	{
		(*s)->next = new_buffer(fd);
		if (!(*s)->next)
			return (NULL);
	}
	return ((*s)->next);
}

void	delete_buffer(int fd)
{
	t_buffer	**s;
	t_buffer	*b;

	s = get_static();
	if (!*s)
		return ;
	if ((*s)->fd == fd)
	{
		b = *s;
		*s = (*s)->next;
		free(b->buffer);
		free(b);
		return ;
	}
	while ((*s)->next && (*s)->next->fd != fd)
		*s = (*s)->next;
	if (!(*s)->next)
		return ;
	b = (*s)->next;
	(*s)->next = b->next;
	free(b->buffer);
	free(b);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:23:59 by bedarenn          #+#    #+#             */
/*   Updated: 2024/01/28 17:15:17 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libgnl.h>
#include <libwati.h>
#include <stdlib.h>
#include <unistd.h>

static int	fill_str(t_list **list, char *buffer)
{
	int		l;
	char	*s;

	l = wati_strlen_set(buffer, '\n');
	s = wati_substr(buffer, 0, l + 1);
	wati_lstadd_back(list, wati_lstnew(s));
	return (l);
}

char	*read_file(t_buffer *b)
{
	int		len;
	t_list	*list;
	char	*str;

	len = 0;
	list = NULL;
	str = NULL;
	if (b->cursor < b->r)
		len = fill_str(&list, b->buffer + b->cursor);
	while (len + b->cursor >= b->r && b->r > 0)
	{
		b->r = read(b->fd, b->buffer, BUFFER_SIZE);
		if (b->r <= 0)
			break ;
		b->buffer[b->r] = '\0';
		b->cursor = 0;
		if (b->r > 0)
			len = fill_str(&list, b->buffer + b->cursor);
	}
	b->cursor += len + 1;
	str = wati_lstjoin(list);
	wati_lstclear(&list, free);
	return (str);
}

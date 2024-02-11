/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_buffer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:31:55 by bedarenn          #+#    #+#             */
/*   Updated: 2023/11/28 17:41:36 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libgnl.h>
#include <stdlib.h>

t_buffer	*new_buffer(int fd)
{
	t_buffer	*buffer;

	buffer = malloc(sizeof(t_buffer));
	if (!buffer)
		return (NULL);
	buffer->buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer->buffer)
	{
		free(buffer);
		return (NULL);
	}
	buffer->fd = fd;
	buffer->r = BUFFER_SIZE;
	buffer->cursor = BUFFER_SIZE;
	buffer->next = NULL;
	return (buffer);
}

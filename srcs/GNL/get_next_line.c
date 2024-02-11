/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:54:49 by bedarenn          #+#    #+#             */
/*   Updated: 2023/11/28 17:41:00 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libgnl.h>
#include <stddef.h>

char	*get_next_line(int fd)
{
	t_buffer	*b;
	char		*str;

	if (BUFFER_SIZE <= 0)
		return (NULL);
	b = get_buffer(fd);
	if (!b)
		return (NULL);
	str = read_file(b);
	if (b->r < BUFFER_SIZE && b->cursor >= b->r)
		delete_buffer(fd);
	return (str);
}

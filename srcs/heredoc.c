/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 16:54:20 by bedarenn          #+#    #+#             */
/*   Updated: 2024/02/14 15:43:34 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <libgnl.h>
#include <fcntl.h>
#include <pipex.h>

char	*heredoc(char *end)
{
	int		fd;
	char	*file;

	file = get_heredoc_name();
	if (!file)
		return (NULL);
	fd = create_file(file);
	if (fd < 0)
		return (NULL);
	end = join_endl(end, fd, file);
	if (!end)
		return (NULL);
	wati_putstr_fd(HEREDOC_PIP, 1);
	write_file(end, fd);
	free(end);
	delete_buffer(0);
	close(fd);
	return (file);
}

char	*get_heredoc_name(void)
{
	int				fd;
	char			*str;

	fd = open("/dev/random", O_RDONLY);
	if (fd < 0)
		return (wati_strdup(HEREDOC));
	str = init_filename(&fd);
	if (!str)
		return (wati_strdup(HEREDOC));
	read_filename(&str, &fd);
	close(fd);
	return (str);
}

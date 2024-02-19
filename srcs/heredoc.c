/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 16:54:20 by bedarenn          #+#    #+#             */
/*   Updated: 2024/02/15 20:01:24 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <libgnl.h>
#include <fcntl.h>
#include <pipex.h>

static void	write_file(char *end, int fd);

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
	write_file(end, fd);
	free(end);
	delete_buffer(0);
	close(fd);
	return (file);
}

char	*get_heredoc_name(void)
{
	int		fd;
	char	*str;

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

static char	*get_line(void);

static void	write_file(char *end, int fd)
{
	size_t	end_len;
	char	*str;

	end_len = wati_strlen(end);
	wati_putstr_fd(HEREDOC_PIP, STDOUT_FILENO);
	str = get_line();
	while (str && wati_strncmp(str, end, end_len))
	{
		write(fd, str, wati_strlen(str));
		free(str);
		wati_putstr_fd(HEREDOC_PIP, STDOUT_FILENO);
		str = get_line();
	}
	if (str)
		free(str);
	else
		wati_putchar_fd('\n', 1);
}

static char	*get_line(void)
{
	char	*str;
	char	*line;

	str = get_next_line(STDIN_FILENO);
	if (!str)
		return (NULL);
	else
	{
		line = wati_strdup(str);
		if (!line)
		{
			free(str);
			return (NULL);
		}
	}
	while (!str || str[wati_strlen(str) - 1] != '\n')
	{
		if (str)
			line = join_free(line, str);
		str = get_next_line(STDIN_FILENO);
	}
	if (str)
		free(str);
	return (line);
}

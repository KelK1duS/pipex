/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:20:39 by bedarenn          #+#    #+#             */
/*   Updated: 2024/02/14 15:46:20 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <libgnl.h>
#include <fcntl.h>
#include <pipex.h>

char	*init_filename(int *fd)
{
	char	*str;

	str = malloc(sizeof(char) * 12);
	if (!str)
	{
		close(*fd);
		return (NULL);
	}
	str[11] = '\0';
	str[0] = '.';
	return (str);
}

char	*read_filename(char **str, int *fd)
{
	char			*str1;
	unsigned char	c;

	str1 = *str + 1;
	while (str1 < *str + 11)
	{
		if (!read(*fd, &c, 1))
		{
			free(*str);
			*str = wati_strdup(HEREDOC);
			return (*str);
		}
		*str1 = c % 93 + 33;
		str1++;
	}
	return (*str);
}

int	create_file(char *str)
{
	int	fd;

	fd = open(str, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		free(str);
		return (fd);
	}
	return (fd);
}

char	*join_endl(char *end, int fd, char *str)
{
	end = wati_strjoin(end, "\n");
	if (!end)
	{
		free(str);
		close(fd);
		return (NULL);
	}
	return (end);
}

void	write_file(char *end, int fd)
{
	size_t	end_len;
	char	*str;

	end_len = wati_strlen(end);
	str = get_next_line(0);
	if (!str)
		str = wati_strdup("");
	while (wati_strncmp(str, end, end_len))
	{
		wati_putstr_fd(str, fd);
		if (wati_strchr(str, '\n'))
			wati_putstr_fd(HEREDOC_PIP, 1);
		free(str);
		str = get_next_line(0);
		if (!str)
			str = wati_strdup("");
	}
	if (str)
		free(str);
}

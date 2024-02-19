/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:20:39 by bedarenn          #+#    #+#             */
/*   Updated: 2024/02/15 19:36:17 by bedarenn         ###   ########.fr       */
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
		if (wati_isalnum(c))
		{
			*str1 = c;
			str1++;
		}
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

char	*join_free(char *s1, char *s2)
{
	char	*str;

	str = wati_strjoin(s1, s2);
	free(s1);
	free(s2);
	return (str);
}

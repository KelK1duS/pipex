/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 16:54:20 by bedarenn          #+#    #+#             */
/*   Updated: 2024/02/11 13:29:25 by bedarenn         ###   ########.fr       */
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
	char	*str;
	char	*endl;
	size_t	end_len;

	str = NULL;
	fd = open(HEREDOC, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
		return (NULL);
	endl = wati_strjoin(end, "\n");
	end_len = wati_strlen(endl);
	wati_putstr_fd("pipe heredoc> ", 1);
	while (!str)
		str = get_next_line(0);
	while (wati_strncmp(str, endl, end_len))
	{
		wati_putstr_fd(str, fd);
		free(str);
		wati_putstr_fd("pipe heredoc> ", 1);
		while (!str)
			str = get_next_line(0);
	}
	if (str)
		free(str);
	else
		wati_putchar_fd('\n', 1);
	free(endl);
	delete_buffer(0);
	close(fd);
	return (wati_strdup(HEREDOC));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_open.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:06:25 by bedarenn          #+#    #+#             */
/*   Updated: 2024/02/26 14:21:33 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

t_fd	open_fd(t_file file, int flags)
{
	t_fd	fd;

	fd.in = open(file.in, O_RDONLY);
	fd.out = open(file.out, flags, 0664);
	if (fd.in < 0)
		perror(file.in);
	if (fd.out < 0)
	{
		perror(file.out);
		close_secure(&fd.in);
		close_secure(&fd.out);
	}
	return (fd);
}

int	dup_std(int in, int out)
{
	if (in > 2)
		if (dup2(in, STDIN_FILENO) == -1
			&& dup2(in, STDIN_FILENO) == -1
			&& dup2(in, STDIN_FILENO) == -1)
			return (-1);
	if (out > 2)
	{
		if (dup2(out, STDOUT_FILENO) == -1
			&& dup2(out, STDOUT_FILENO) == -1
			&& dup2(out, STDOUT_FILENO) == -1)
		{
			close(STDIN_FILENO);
			return (-1);
		}
	}
	return (1);
}

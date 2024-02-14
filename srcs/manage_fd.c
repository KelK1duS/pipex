/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_fd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 12:59:01 by bedarenn          #+#    #+#             */
/*   Updated: 2024/02/14 16:14:19 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

void	close_secure(int *fd)
{
	if (*fd >= 0)
		close(*fd);
	*fd = -1;
}

void	close_pip(int pip[2])
{
	close_secure(pip);
	close_secure(pip + 1);
}

void	close_all(t_fd *fd)
{
	close_secure(&(fd->in));
	close_secure(&(fd->out));
	close_pip(fd->pip);
}

void	close_classic(t_fd *fd)
{
	close_secure(&fd->in);
	close_secure(&fd->pip[1]);
	fd->in = fd->pip[0];
	fd->pip[0] = -1;
}

t_fd	open_fd(t_file file, int flags)
{
	t_fd	fd;

	fd.in = open(file.in, O_RDONLY);
	if (fd.in < 0)
	{
		perror(file.in);
		return (fd);
	}
	fd.out = open(file.out, flags, 0664);
	if (fd.out < 0)
	{
		perror(file.out);
		close(fd.in);
		fd.in = -1;
	}
	return (fd);
}

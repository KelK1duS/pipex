/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_close.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 12:59:01 by bedarenn          #+#    #+#             */
/*   Updated: 2024/02/23 14:36:20 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>
#include <unistd.h>

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

void	close_std(void)
{
	close(STDOUT_FILENO);
	close(STDIN_FILENO);
}

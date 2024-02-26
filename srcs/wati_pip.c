/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wati_pip.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:47:25 by bedarenn          #+#    #+#             */
/*   Updated: 2024/02/26 14:13:07 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>
#include <unistd.h>

static void	exit_path(t_list **pids, t_fd *fd);

void	wati_pip(t_fd fd, t_exec exec, char **argv)
{
	t_list	*pids;

	pids = NULL;
	if (pipe(fd.pip))
		return (exit_path(&pids, &fd));
	if (fd.in > 2)
		if (wati_fork(&fd, exec, *argv, &pids) == -1)
			return (exit_path(&pids, &fd));
	argv++;
	close_classic(&fd);
	while (argv[2])
	{
		if (pipe(fd.pip) || wati_fork(&fd, exec, *argv, &pids) == -1)
			return (exit_path(&pids, &fd));
		argv++;
		close_classic(&fd);
	}
	wati_fork_o(&fd, exec, *argv, &pids);
	exit_path(&pids, &fd);
}

static void	exit_path(t_list **pids, t_fd *fd)
{
	close_secure(&fd->in);
	close_secure(&fd->out);
	wati_lstclear(pids, free_pid);
}

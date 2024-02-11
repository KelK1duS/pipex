/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wati_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:47:25 by bedarenn          #+#    #+#             */
/*   Updated: 2024/02/11 14:34:06 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <pipex.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <libwati.h>

static void	wati_fork_input(t_fd *fd, t_cmd *cmd, t_list **pids, char **envp)
{
	pid_t	pid;

	pid = fork();
	if (!pid)
	{
		dup2(fd->in, STDIN_FILENO);
		dup2(fd->pip[1], STDOUT_FILENO);
		close_all(fd);
		execve(cmd->path, cmd->strs, envp);
		exit(EXIT_FAILURE);
	}
	add_pid(pids, pid);
}

static void	wati_fork(t_fd *fd, t_cmd *cmd, t_list **pids, char **envp)
{
	pid_t	pid;

	pid = fork();
	if (!pid)
	{
		dup2(fd->in, STDIN_FILENO);
		dup2(fd->pip[1], STDOUT_FILENO);
		close_all(fd);
		execve(cmd->path, cmd->strs, envp);
		exit(EXIT_FAILURE);
	}
	add_pid(pids, pid);
}

static void	wati_fork_output(t_fd *fd, t_cmd *cmd, t_list **pids, char **envp)
{
	pid_t	pid;

	pid = fork();
	if (!pid)
	{
		dup2(fd->in, STDIN_FILENO);
		dup2(fd->out, STDOUT_FILENO);
		execve(cmd->path, cmd->strs, envp);
		exit(EXIT_FAILURE);
	}
	add_pid(pids, pid);
}

void	wati_pip(t_fd fd, t_list *cmds, char **envp)
{
	t_list	*pids;

	pids = NULL;
	if (pipe(fd.pip))
		return ;
	if (test_path(cmds->content))
		wati_fork_input(&fd, cmds->content, &pids, envp);
	close_classic(&fd, &cmds);
	while (cmds->next)
	{
		if (pipe(fd.pip))
		{
			wati_lstclear(&pids, free_pid);
			return ;
		}
		if (test_path(cmds->content))
			wati_fork(&fd, cmds->content, &pids, envp);
		close_classic(&fd, &cmds);
	}
	if (test_path(cmds->content))
		wati_fork_output(&fd, cmds->content, &pids, envp);
	close_secure(&fd.in);
	close_secure(&fd.out);
	wati_lstclear(&pids, free_pid);
}

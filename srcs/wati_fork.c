/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wati_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:47:25 by bedarenn          #+#    #+#             */
/*   Updated: 2024/02/19 13:46:41 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <pipex.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <libwati.h>
#include <stdio.h>

static void	close_std(void)
{
	close(STDERR_FILENO);
	close(STDOUT_FILENO);
	close(STDIN_FILENO);
}

static void	dup_std(int in, int out)
{
	if (in > 2)
		dup2(in, STDIN_FILENO);
	if (out > 2)
		dup2(out, STDOUT_FILENO);
}

static void	wati_fork(t_fd *fd, t_exec exec, char *str, t_list **pids)
{
	t_cmd	*cmd;
	pid_t	pid;

	pid = fork();
	if (!pid)
	{
		dup_std(fd->in, fd->pip[1]);
		close_all(fd);
		cmd = get_cmd(str, exec.path);
		if (cmd && cmd->strs && *cmd->strs)
		{
			if (cmd->path)
				execve(cmd->path, cmd->strs, exec.envp);
			else
				execve(cmd->strs[0], cmd->strs, exec.envp);
		}
		if (cmd)
			free_cmd(cmd);
		wati_lstclear(pids, free);
		wati_free_tab(exec.path);
		close_std();
		exit(EXIT_FAILURE);
	}
	add_pid(pids, pid);
}

static void	wati_fork_o(t_fd *fd, t_exec exec, char *str, t_list **pids)
{
	t_cmd	*cmd;
	pid_t	pid;

	pid = fork();
	if (!pid)
	{
		dup_std(fd->in, fd->out);
		close_secure(&fd->in);
		close_secure(&fd->out);
		cmd = get_cmd(str, exec.path);
		if (cmd && cmd->strs && *cmd->strs)
		{
			if (cmd->path)
				execve(cmd->path, cmd->strs, exec.envp);
			else
				execve(cmd->strs[0], cmd->strs, exec.envp);
		}
		if (cmd)
			free_cmd(cmd);
		wati_lstclear(pids, free);
		wati_free_tab(exec.path);
		close_std();
		exit(EXIT_FAILURE);
	}
	add_pid(pids, pid);
}

void	wati_pip(t_fd fd, t_exec exec, char **argv)
{
	t_list	*pids;

	pids = NULL;
	if (pipe(fd.pip))
		return ;
	if (fd.in > 2)
		wati_fork(&fd, exec, *argv, &pids);
	argv++;
	close_classic(&fd);
	while (argv[2])
	{
		if (pipe(fd.pip))
		{
			wati_lstclear(&pids, free_pid);
			return ;
		}
		wati_fork(&fd, exec, *argv, &pids);
		argv++;
		close_classic(&fd);
	}
	wati_fork_o(&fd, exec, *argv, &pids);
	close_secure(&fd.in);
	close_secure(&fd.out);
	wati_lstclear(&pids, free_pid);
}

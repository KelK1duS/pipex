/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wati_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:58:36 by bedarenn          #+#    #+#             */
/*   Updated: 2024/02/26 14:20:31 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>
#include <stdlib.h>
#include <unistd.h>

static void	wati_execve(t_cmd	*cmd, char **envp);
static void	free_fork(t_list **pids, char **path);

int	wati_fork(t_fd *fd, t_exec exec, char *str, t_list **pids)
{
	t_cmd	*cmd;
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		return (-1);
	if (!pid)
	{
		if (dup_std(fd->in, fd->pip[1]) == -1)
		{
			close_all(fd);
			free_fork(pids, exec.path);
		}
		dup2(fd->in, STDIN_FILENO);
		dup2(fd->pip[1], STDOUT_FILENO);
		close_all(fd);
		cmd = get_cmd(str, exec.path);
		wati_execve(cmd, exec.envp);
		if (cmd)
			free_cmd(cmd);
		close_std();
		free_fork(pids, exec.path);
	}
	add_pid(pids, pid);
	return (pid);
}

int	wati_fork_o(t_fd *fd, t_exec exec, char *str, t_list **pids)
{
	t_cmd	*cmd;
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		return (-1);
	if (!pid)
	{
		if (dup_std(fd->in, fd->out) == -1)
		{
			close_all(fd);
			free_fork(pids, exec.path);
		}
		close_secure(&fd->in);
		close_secure(&fd->out);
		cmd = get_cmd(str, exec.path);
		wati_execve(cmd, exec.envp);
		if (cmd)
			free_cmd(cmd);
		close_std();
		free_fork(pids, exec.path);
	}
	add_pid(pids, pid);
	return (pid);
}

static void	wati_execve(t_cmd	*cmd, char **envp)
{
	if (cmd && cmd->strs && *cmd->strs)
	{
		if (cmd->path)
			execve(cmd->path, cmd->strs, envp);
		else
			execve(cmd->strs[0], cmd->strs, envp);
	}
}

static void	free_fork(t_list **pids, char **path)
{
	wati_lstclear(pids, free);
	wati_free_tab(path);
	exit(EXIT_FAILURE);
}

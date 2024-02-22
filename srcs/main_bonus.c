/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 18:50:39 by bedarenn          #+#    #+#             */
/*   Updated: 2024/02/22 18:18:10 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <libwati.h>

int	wati_error(void)
{
	wati_putstr_fd("Error\n", 2);
	return (1);
}

int	main_heredoc(int argc, char **argv, char **envp)
{
	t_file	file;
	t_fd	fd;
	t_exec	exec;

	file.out = argv[argc - 1];
	exec = build_cmds(envp);
	if (!exec.path)
		return (wati_error());
	file.in = heredoc(argv[2]);
	fd = open_fd(file, O_WRONLY | O_CREAT | O_APPEND);
	if (fd.out > 2 && fd.in > 2)
	{
		unlink(file.in);
		free(file.in);
		wati_pip(fd, exec, argv + 3);
	}
	else
	{
		unlink(file.in);
		free(file.in);
		wati_free_tab(exec.path);
		return (1);
	}
	wati_free_tab(exec.path);
	return (0);
}

int	main_file(int argc, char **argv, char **envp)
{
	t_file	file;
	t_fd	fd;
	t_exec	exec;

	if (argc < 5)
		return (1);
	file.out = argv[argc - 1];
	exec = build_cmds(envp);
	if (!exec.path)
		return (wati_error());
	file.in = argv[1];
	fd = open_fd(file, O_WRONLY | O_CREAT | O_TRUNC);
	if (fd.out >= 0)
		wati_pip(fd, exec, argv + 2);
	else
	{
		wati_free_tab(exec.path);
		return (1);
	}
	wati_free_tab(exec.path);
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	if (argc >= 6 && !wati_strncmp(argv[1], HEREDOC, wati_strlen(HEREDOC)))
		return (main_heredoc(argc, argv, envp));
	return (main_file(argc, argv, envp));
}

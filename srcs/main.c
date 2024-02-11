/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 18:50:39 by bedarenn          #+#    #+#             */
/*   Updated: 2024/02/11 13:36:11 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>
#include <unistd.h>
#include <fcntl.h>

void	print_list(t_list *list)
{
	while (list)
	{
		wati_putstrs_fd(list->content, 1);
		wati_putchar_fd('\n', 1);
		list = list->next;
	}
}

t_list	*build_cmds(char **argv, char **envp)
{
	char	**path;
	t_list	*list;

	path = wati_split(get_var(envp, "PATH=") + 5, ':');
	if (!path)
	{
		wati_putstr_fd("Failed building PATH\n", 2);
		return (NULL);
	}
	list = get_cmds(argv, path);
	if (!list)
	{
		wati_putstr_fd("Failed building commands\n", 2);
		return (NULL);
	}
	if (wati_lstsize(list) < 2)
	{
		wati_putstr_fd("Need 2 commands for working\n", 2);
		return (NULL);
	}
	wati_free_tab(path);
	return (list);
}

int	main(int argc, char **argv, char **envp)
{
	t_file	file;
	t_fd	fd;
	t_list	*cmds;

	file.out = argv[argc - 1];
	if (!wati_strncmp(argv[1], HEREDOC, wati_strlen(HEREDOC)))
	{
		cmds = build_cmds(argv + 3, envp);
		if (!cmds)
			return (1);
		file.in = heredoc(argv[2]);
		fd = open_fd(file, O_WRONLY | O_CREAT | O_APPEND);
	}
	else
	{
		cmds = build_cmds(argv + 2, envp);
		if (!cmds)
			return (1);
		file.in = argv[1];
		fd = open_fd(file, O_WRONLY | O_CREAT | O_TRUNC);
	}
	if (fd.in >= 0 && fd.out >= 0)
		wati_pip(fd, cmds, envp);
	wati_lstclear(&cmds, free_cmd);
	return (0);
}

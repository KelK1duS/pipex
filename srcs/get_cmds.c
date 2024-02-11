/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmds.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:22:45 by bedarenn          #+#    #+#             */
/*   Updated: 2024/01/29 20:39:12 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>
#include <stdlib.h>

void	free_cmd(void *ptr)
{
	t_cmd	*cmd;

	if (!ptr)
		return ;
	cmd = ptr;
	if (cmd->strs)
		wati_free_tab(cmd->strs);
	if (cmd->path)
		free(cmd->path);
	free(cmd);
}

static t_cmd	*get_cmd(char *str, char **path)
{
	t_cmd	*cmd;

	cmd = malloc(sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	cmd->strs = wati_split(str, ' ');
	if (!cmd->strs)
	{
		free(cmd);
		return (NULL);
	}
	cmd->path = get_path(path, cmd->strs);
	return (cmd);
}

static t_list	*get_lstcmd(char *str, char	**path)
{
	t_list	*list;
	t_cmd	*cmd;

	cmd = get_cmd(str, path);
	if (!cmd)
		return (NULL);
	list = wati_lstnew(cmd);
	if (!list)
	{
		free_cmd(cmd);
		return (NULL);
	}
	return (list);
}

t_list	*get_cmds(char **argv, char	**path)
{
	t_list	*list;
	t_list	*lst;

	list = NULL;
	if (!*argv)
		return (NULL);
	while (argv[1])
	{
		lst = get_lstcmd(*argv, path);
		if (!lst)
		{
			wati_lstclear(&list, wati_free_tab);
			return (NULL);
		}
		wati_lstadd_back(&list, lst);
		argv++;
	}
	return (list);
}

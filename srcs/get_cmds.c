/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmds.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:22:45 by bedarenn          #+#    #+#             */
/*   Updated: 2024/02/13 17:06:48 by bedarenn         ###   ########.fr       */
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

t_cmd	*get_cmd(char *str, char **path)
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

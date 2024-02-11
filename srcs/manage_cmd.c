/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 18:01:24 by bedarenn          #+#    #+#             */
/*   Updated: 2024/02/11 13:38:13 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>
#include <unistd.h>

t_cmd	*get_list_cmd(t_list *list)
{
	return (list->content);
}

int	test_path(t_cmd *cmd)
{
	if (!cmd->path)
	{
		wati_fprintf(2, "zsh: command not found: %s\n",
			cmd->strs[0]);
		return (0);
	}
	return (1);
}

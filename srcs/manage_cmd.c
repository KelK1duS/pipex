/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 18:01:24 by bedarenn          #+#    #+#             */
/*   Updated: 2024/02/13 17:30:28 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>
#include <unistd.h>

int	test_path(t_cmd *cmd)
{
	if (!cmd->path)
	{
		wati_fprintf(2, "pipex: command not found: %s\n",
			cmd->strs[0]);
		return (0);
	}
	return (1);
}

t_exec	build_cmds(char **envp)
{
	t_exec	exec;
	char	*str;

	exec.path = NULL;
	exec.envp = envp;
	str = get_var(envp, "PATH=");
	if (!str)
		return (exec);
	exec.path = wati_split(str + 5, ':');
	return (exec);
}

void	print_cmd(t_cmd *cmd)
{
	wati_putendl_fd(cmd->path, 2);
	wati_putstrs_fd(cmd->strs, 2);
	wati_putchar_fd('\n', 2);
}

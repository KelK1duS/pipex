/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 18:46:41 by bedarenn          #+#    #+#             */
/*   Updated: 2024/02/11 13:43:41 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <libwati.h>
# include <sys/types.h>

# define HEREDOC "here_doc"

typedef struct s_file
{
	char	*in;
	char	*out;
}	t_file;

typedef struct s_fd
{
	int	in;
	int	out;
	int	pip[2];
}	t_fd;

typedef struct s_cmd
{
	char	**strs;
	char	*path;
}	t_cmd;

void	free_cmd(void *cmd);
char	*get_var(char **envp, char *lf);
t_cmd	*get_list_cmd(t_list *list);
t_list	*get_cmds(char **argv, char	**path);
char	*get_path(char **path, char **cmd);
int		test_path(t_cmd *cmd);
void	wati_pip(t_fd fd, t_list *cmds, char **envp);
char	*heredoc(char *end);
t_list	*add_pid(t_list **list, pid_t pid);
void	free_pid(void *ptr);

void	close_secure(int *fd);
void	close_pip(int pip[2]);
void	close_all(t_fd	*fd);
void	close_classic(t_fd *fd, t_list **list);
t_fd	open_fd(t_file file, int flags);

#endif
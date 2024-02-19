/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 18:46:41 by bedarenn          #+#    #+#             */
/*   Updated: 2024/02/15 19:36:35 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <libwati.h>
# include <sys/types.h>

# define HEREDOC "here_doc"
# define HEREDOC_PIP "pipe heredoc> "

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

typedef struct s_exec
{
	char	**path;
	char	**envp;
}	t_exec;

int		wati_error(void);

t_cmd	get_list_cmd(t_list *list);
t_exec	build_cmds(char **envp);
void	print_cmd(t_cmd *cmd);

t_cmd	*get_cmd(char *str, char **path);
int		test_path(t_cmd *cmd);

char	*heredoc(char *end);
char	*get_heredoc_name(void);

char	*init_filename(int *fd);
char	*read_filename(char **str, int *fd);
int		create_file(char *str);
char	*join_endl(char *end, int fd, char *str);
char	*join_free(char *s1, char *s2);

void	free_cmd(void *cmd);
char	*get_var(char **envp, char *lf);
char	*get_path(char **path, char **cmd);
t_list	*add_pid(t_list **list, pid_t pid);
void	free_pid(void *ptr);

void	wati_pip(t_fd fd, t_exec exec, char **argv);

void	close_secure(int *fd);
void	close_pip(int pip[2]);
void	close_all(t_fd	*fd);
void	close_classic(t_fd *fd);
t_fd	open_fd(t_file file, int flags);

#endif
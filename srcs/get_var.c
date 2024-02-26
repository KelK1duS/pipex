/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 18:54:13 by bedarenn          #+#    #+#             */
/*   Updated: 2024/02/23 14:08:37 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libwati.h>
#include <unistd.h>
#include <stdlib.h>

char	*get_var(char **envp, char *lf)
{
	size_t	size;

	size = wati_strlen(lf);
	while (*envp)
	{
		if (!wati_strncmp(*envp, lf, size))
			return (*envp);
		envp++;
	}
	return (NULL);
}

char	*get_path(char **path, char **cmd)
{
	char	*str0;
	char	*str1;

	if (!cmd || !*cmd || !**cmd)
		return (NULL);
	while (*path)
	{
		str0 = wati_strjoin(*path, "/");
		str1 = wati_strjoin(str0, *cmd);
		free(str0);
		if (!access(str1, X_OK))
			return (str1);
		free(str1);
		path++;
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 18:54:13 by bedarenn          #+#    #+#             */
/*   Updated: 2024/01/29 20:39:25 by bedarenn         ###   ########.fr       */
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

	while (*path)
	{
		str0 = wati_strjoin(*path, "/");
		str1 = wati_strjoin(str0, *cmd);
		free(str0);
		if (!access(str1, F_OK))
		{
			if (access(str1, X_OK))
			{
				free(str1);
				wati_printf("CAN'T EXEC : %s\n", str1);
				return (NULL);
			}
			return (str1);
		}
		free(str1);
		path++;
	}
	return (NULL);
}

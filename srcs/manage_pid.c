/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_pid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 17:22:34 by bedarenn          #+#    #+#             */
/*   Updated: 2024/02/10 14:07:15 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <libwati.h>
#include <stdlib.h>
#include <sys/wait.h>

t_list	*add_pid(t_list **list, pid_t pid)
{
	pid_t	*ptr;
	t_list	*lst;

	ptr = malloc(sizeof(pid_t));
	if (!ptr)
		return (NULL);
	*ptr = pid;
	lst = wati_lstnew(ptr);
	if (!lst)
		return (NULL);
	wati_lstadd_front(list, lst);
	return (lst);
}

void	free_pid(void *ptr)
{
	waitpid(*((pid_t *)ptr), NULL, 0);
	free(ptr);
}

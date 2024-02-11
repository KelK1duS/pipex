/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wati_lstsplit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:34:47 by bedarenn          #+#    #+#             */
/*   Updated: 2024/01/21 15:40:24 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libwati.h>
#include <stdlib.h>

char	**wati_lstsplit(t_list *list)
{
	char	**strs0;
	char	**strs;
	size_t	size;

	size = wati_lstsize(list);
	strs0 = malloc(sizeof(char *) * (size + 1));
	if (!strs0)
		return (NULL);
	strs0[size] = NULL;
	strs = strs0;
	while (list)
	{
		*strs = list->content;
		list = list->next;
		strs++;
	}
	return (strs0);
}

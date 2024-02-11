/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wati_lstjoin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:46:27 by bedarenn          #+#    #+#             */
/*   Updated: 2024/01/21 15:46:28 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libwati.h>
#include <stdlib.h>

static size_t	wati_listlen(t_list *list)
{
	size_t	len;

	len = 0;
	while (list)
	{
		if (list->content)
			len += wati_strlen(list->content);
		list = list->next;
	}
	return (len);
}

static void	fillstr(char *str, t_list *list)
{
	size_t	len;

	while (list)
	{
		if (list->content)
		{
			len = wati_strlen(list->content);
			wati_memcpy(str, list->content, len);
			str += len;
		}
		list = list->next;
	}
}

char	*wati_lstjoin(t_list *list)
{
	char	*str;
	size_t	len;

	if (!list)
		return (NULL);
	len = wati_listlen(list);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	fillstr(str, list);
	return (str);
}

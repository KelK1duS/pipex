/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wati_lstmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 22:33:15 by bedarenn          #+#    #+#             */
/*   Updated: 2024/01/21 15:40:15 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libwati.h>

t_list	*wati_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*list0;
	t_list	*list;

	if (!lst || !f || !del)
		return (NULL);
	list = wati_lstnew(f(lst->content));
	lst = lst->next;
	if (!list)
		return (NULL);
	list0 = list;
	while (lst)
	{
		list->next = wati_lstnew(f(lst->content));
		if (!list->next)
		{
			wati_lstclear(&list0, del);
			return (NULL);
		}
		lst = lst->next;
		list = list->next;
	}
	return (list0);
}

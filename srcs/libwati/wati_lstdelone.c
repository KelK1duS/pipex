/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wati_lstdelone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 19:35:40 by bedarenn          #+#    #+#             */
/*   Updated: 2024/01/21 15:53:05 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libwati.h>
#include <stdlib.h>

void	wati_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!del || !lst)
		return ;
	if (lst->content)
		del(lst->content);
	free(lst);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wati_lstclean.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:31:21 by bedarenn          #+#    #+#             */
/*   Updated: 2024/01/21 15:53:01 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libwati.h>
#include <stdlib.h>

void	wati_lstclean(t_list **lst)
{
	if (!lst || !*lst)
		return ;
	wati_lstclean(&(*lst)->next);
	free(*lst);
	*lst = NULL;
}

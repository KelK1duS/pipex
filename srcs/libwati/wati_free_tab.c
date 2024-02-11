/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wati_free_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:43:38 by bedarenn          #+#    #+#             */
/*   Updated: 2024/01/21 15:53:02 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libwati.h>
#include <stdlib.h>

void	wati_free_tab(void *ptr)
{
	char	**tab;

	tab = ptr;
	if (!tab)
		return ;
	while (*tab)
		free(*(tab++));
	free(ptr);
}

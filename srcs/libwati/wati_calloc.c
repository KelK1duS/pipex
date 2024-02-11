/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wati_calloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 08:43:15 by bedarenn          #+#    #+#             */
/*   Updated: 2024/01/21 15:45:14 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libwati.h>
#include <stdlib.h>

void	*wati_calloc(size_t nmemb, size_t size)
{
	void				*p;
	unsigned long long	total;

	if (!size || !nmemb)
		return (malloc(0));
	total = nmemb * size;
	if (total / size != nmemb)
		return (NULL);
	p = malloc(total);
	if (!p)
		return (NULL);
	wati_bzero(p, total);
	return (p);
}

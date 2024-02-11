/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wati_memset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:09:16 by bedarenn          #+#    #+#             */
/*   Updated: 2024/01/21 15:40:38 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libwati.h>

void	*wati_memset(void *s0, int c, size_t n)
{
	char	*s;

	s = (char *)s0;
	while (n > 0)
	{
		*s = c;
		s++;
		n--;
	}
	return (s0);
}

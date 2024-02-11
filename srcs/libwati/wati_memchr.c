/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wati_memchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:47:50 by bedarenn          #+#    #+#             */
/*   Updated: 2024/01/21 15:40:26 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libwati.h>

void	*wati_memchr(const void *s0, int c, size_t n)
{
	char	*s;
	char	t;

	if (n == 0)
		return (0);
	s = (char *)s0;
	n--;
	t = (char)c;
	while (*s != t && n)
	{
		s++;
		n--;
	}
	if (*s == t)
		return ((void *)s);
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wati_strlen_set.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 09:43:51 by bedarenn          #+#    #+#             */
/*   Updated: 2024/01/21 15:41:15 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libwati.h>

size_t	wati_strlen_set(const char *s0, int c)
{
	char	*s;

	s = (char *)s0;
	while (*s != (char)c && *s)
		s++;
	return (s - s0);
}

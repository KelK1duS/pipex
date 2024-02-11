/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wati_strrchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:33:48 by bedarenn          #+#    #+#             */
/*   Updated: 2024/01/21 15:41:40 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libwati.h>

char	*wati_strrchr(const char *s0, int c)
{
	char	*s;
	char	t;

	s = (char *)s0 + wati_strlen(s0);
	t = (char)c;
	while (s > s0 && *s != t)
		s--;
	if (*s == t)
		return (s);
	return (NULL);
}

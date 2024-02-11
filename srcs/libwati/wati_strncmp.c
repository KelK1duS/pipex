/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wati_strncmp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:44:26 by bedarenn          #+#    #+#             */
/*   Updated: 2024/01/21 15:41:26 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libwati.h>

int	wati_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	s1_len;
	size_t	s2_len;

	s1_len = wati_strlen(s1) + 1;
	s2_len = wati_strlen(s2) + 1;
	if (n > s1_len || n > s2_len)
	{
		if (s1_len < s2_len)
			return (wati_memcmp(s1, s2, s1_len));
		else
			return (wati_memcmp(s1, s2, s2_len));
	}
	return (wati_memcmp(s1, s2, n));
}

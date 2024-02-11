/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wati_strlcpy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 10:41:19 by bedarenn          #+#    #+#             */
/*   Updated: 2024/01/21 15:41:12 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libwati.h>

size_t	wati_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_len;

	src_len = wati_strlen(src);
	if (src_len + 1 < size)
		wati_memcpy(dst, src, src_len + 1);
	else if (size != 0)
	{
		wati_memcpy(dst, src, size - 1);
		dst[size - 1] = '\0';
	}
	return (src_len);
}

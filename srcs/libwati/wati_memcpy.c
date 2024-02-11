/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wati_memcpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:39:30 by bedarenn          #+#    #+#             */
/*   Updated: 2024/01/21 15:40:32 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libwati.h>

void	*wati_memcpy(void *dest0, const void *src0, size_t n)
{
	unsigned char	*dest;
	unsigned char	*src;

	if (n == 0 || dest0 == src0)
		return (dest0);
	dest = (unsigned char *)dest0;
	src = (unsigned char *)src0;
	while (n > 0)
	{
		*dest = *src;
		dest++;
		src++;
		n--;
	}
	return (dest0);
}

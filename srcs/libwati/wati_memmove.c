/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wati_memmove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:07:10 by bedarenn          #+#    #+#             */
/*   Updated: 2024/01/21 15:40:35 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libwati.h>

void	*wati_memmove(void *dest0, const void *src0, size_t n)
{
	unsigned char	*dest;
	unsigned char	*src;

	if (dest0 > src0)
	{
		dest = (unsigned char *)dest0 + n - 1;
		src = (unsigned char *)src0 + n - 1;
		while (n > 0)
		{
			*dest = *src;
			dest--;
			src--;
			n--;
		}
	}
	else
	{
		dest = wati_memcpy(dest0, src0, n);
	}
	return (dest0);
}

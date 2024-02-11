/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wati_atou_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:35:08 by bedarenn          #+#    #+#             */
/*   Updated: 2024/01/21 16:21:43 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libwati.h>

static int	wati_ischarset(char c, char *charset0)
{
	char	*charset;

	charset = charset0;
	while (c != *charset && *charset)
		charset++;
	if (!*charset)
		return (-1);
	return (charset - charset0);
}

size_t	wati_atou_base(const char *nptr, char *base, size_t size)
{
	size_t	n;

	while (wati_isspace(*nptr))
		nptr++;
	n = 0;
	while (wati_ischarset(*nptr, base) >= 0)
	{
		n = n * size + wati_ischarset(*nptr, base);
		nptr++;
	}
	return (n);
}

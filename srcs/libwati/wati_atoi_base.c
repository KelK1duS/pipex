/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wati_atoi_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 08:57:07 by bedarenn          #+#    #+#             */
/*   Updated: 2024/02/11 14:34:14 by bedarenn         ###   ########.fr       */
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

int	wati_atoi_base(const char *nptr, char *base, size_t size)
{
	int		s;
	size_t	n;

	while (wati_isspace(*nptr))
		nptr++;
	if (*nptr == '-')
	{
		s = -1;
		nptr++;
	}
	else if (*nptr == '+')
	{
		s = 1;
		nptr++;
	}
	else
		s = 1;
	n = 0;
	while (wati_ischarset(*nptr, base) >= 0)
	{
		n = n * size + wati_ischarset(*nptr, base);
		nptr++;
	}
	return (s * n);
}

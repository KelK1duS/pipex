/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wati_atoll.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:15:13 by bedarenn          #+#    #+#             */
/*   Updated: 2024/01/21 15:39:15 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libwati.h>

long	wati_atoll(const char *nptr)
{
	long	s;
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
	while (wati_isdigit(*nptr))
	{
		n = n * 10 + (*nptr - 48);
		nptr++;
	}
	return (s * n);
}

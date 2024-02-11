/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wati_atoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 08:57:07 by bedarenn          #+#    #+#             */
/*   Updated: 2024/01/21 15:38:29 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libwati.h>

int	wati_atoi(const char *nptr)
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
	while (wati_isdigit(*nptr))
	{
		n = n * 10 + (*nptr - 48);
		nptr++;
	}
	return (s * n);
}

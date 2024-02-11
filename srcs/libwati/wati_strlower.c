/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wati_strlower.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:27:14 by bedarenn          #+#    #+#             */
/*   Updated: 2024/01/21 15:41:21 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libwati.h>

char	*wati_strlower(char *str0)
{
	char	*str;

	str = str0;
	while (*str)
	{
		*str = wati_tolower(*str);
		str++;
	}
	return (str0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wati_strupper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:28:51 by bedarenn          #+#    #+#             */
/*   Updated: 2024/01/21 16:21:19 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libwati.h>

char	*wati_strupper(char *str0)
{
	char	*str;

	str = str0;
	while (*str)
	{
		*str = wati_toupper(*str);
		str++;
	}
	return (str0);
}

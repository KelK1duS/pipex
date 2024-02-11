/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wati_strlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:57:21 by bedarenn          #+#    #+#             */
/*   Updated: 2024/01/21 15:41:18 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libwati.h>

size_t	wati_strlen(const char *str0)
{
	const char	*str;

	str = str0;
	while (*str)
		++str;
	return (str - str0);
}

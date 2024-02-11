/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wati_striteri.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:07:43 by bedarenn          #+#    #+#             */
/*   Updated: 2024/01/21 15:41:04 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libwati.h>

void	wati_striteri(char *s0, void (*f)(unsigned int, char*))
{
	char	*s;

	if (!s0 || !f)
		return ;
	s = s0;
	while (*s)
	{
		f(s - s0, s);
		s++;
	}
}

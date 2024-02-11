/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wati_strmapi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 11:34:29 by bedarenn          #+#    #+#             */
/*   Updated: 2024/01/21 15:46:49 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libwati.h>
#include <stdlib.h>

char	*wati_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char		*str;
	size_t		len;

	if (!s || !f)
		return (NULL);
	len = wati_strlen(s);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = s[len];
	while (len)
	{
		len--;
		str[len] = f(len, s[len]);
	}
	return (str);
}

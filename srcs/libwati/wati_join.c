/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wati_join.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:46:29 by bedarenn          #+#    #+#             */
/*   Updated: 2024/01/21 15:45:29 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libwati.h>
#include <stdlib.h>

static size_t	wati_strslen(char **strs)
{
	size_t	len;

	len = 0;
	while (*strs)
	{
		len += wati_strlen(*strs);
		strs++;
	}
	return (len);
}

static void	fillstr(char *str, char **strs)
{
	size_t	len;

	while (*strs)
	{
		len = wati_strlen(*strs);
		wati_memcpy(str, *strs, len);
		str += len;
		strs++;
	}
}

char	*wati_join(char **strs)
{
	char	*str;
	size_t	len;

	len = wati_strslen(strs);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	fillstr(str, strs);
	return (str);
}

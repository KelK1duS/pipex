/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wati_substr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 11:05:51 by bedarenn          #+#    #+#             */
/*   Updated: 2024/01/21 15:46:56 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libwati.h>
#include <stdlib.h>

char	*wati_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	size_t	start_len;
	char	*str;

	if (!s)
		return (NULL);
	s_len = wati_strlen(s);
	if (s_len < start)
		return (wati_strdup(""));
	start_len = wati_strlen(s + start);
	if (start_len < len)
		len = start_len;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str = wati_memcpy(str, s + start, len);
	str[len] = '\0';
	return (str);
}

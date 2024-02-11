/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wati_strtrim.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 12:36:51 by bedarenn          #+#    #+#             */
/*   Updated: 2024/01/21 15:46:53 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libwati.h>
#include <stdlib.h>

static int	wati_ischarset(char c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*wati_strtrim(char const *s, char const *set)
{
	char	*s_start;
	char	*s_end;
	size_t	str_len;
	char	*str;

	if (!s)
		return (NULL);
	s_start = (char *)s;
	while (*s_start && wati_ischarset(*s_start, set))
		s_start++;
	s_end = (char *)s + wati_strlen(s) - 1;
	if (s_start >= s_end)
		return (wati_strdup(""));
	while (s_end != s && wati_ischarset(*s_end, set))
		s_end--;
	str_len = s_end - s_start + 1;
	str = malloc(sizeof(char) * (str_len + 1));
	if (!str)
		return (NULL);
	str = wati_memcpy(str, s_start, str_len);
	str[str_len] = '\0';
	return (str);
}

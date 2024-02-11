/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wati_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 17:43:20 by bedarenn          #+#    #+#             */
/*   Updated: 2024/01/21 15:53:09 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libwati.h>
#include <stdlib.h>

static size_t	count_word(const char *s, char c)
{
	size_t	n;

	if (!s)
		return (0);
	while (*s == c && *s)
		s++;
	n = 0;
	while (*s)
	{
		n++;
		while (*s != c && *s)
			s++;
		while (*s == c && *s)
			s++;
	}
	return (n);
}

static size_t	wati_strlen_tocharset(const char *str0, char c)
{
	const char	*str;

	str = str0;
	while (*str && *str != c)
		str++;
	return (str - str0);
}

static char	**fill_tab(const char *s, char c, char **strs, size_t	strs_len)
{
	size_t	i;
	size_t	s_len;

	while (*s && *s == c)
		s++;
	i = 0;
	while (i < strs_len)
	{
		s_len = wati_strlen_tocharset(s, c);
		strs[i] = wati_substr(s, 0, s_len);
		if (!strs[i])
		{
			wati_free_tab(strs);
			return (NULL);
		}
		s += s_len;
		while (*s == c)
			s++;
		i++;
	}
	strs[strs_len] = NULL;
	return (strs);
}

char	**wati_split(const char *s, char c)
{
	char	**strs;
	size_t	strs_len;

	if (!s)
		return (NULL);
	strs_len = count_word(s, c);
	strs = malloc(sizeof(char *) * (strs_len + 1));
	if (!strs)
		return (NULL);
	if (!fill_tab(s, c, strs, strs_len))
		return (NULL);
	return (strs);
}

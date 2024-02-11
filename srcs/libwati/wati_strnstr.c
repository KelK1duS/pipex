/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wati_strnstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 09:44:21 by bedarenn          #+#    #+#             */
/*   Updated: 2024/01/21 15:41:29 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libwati.h>

char	*wati_strnstr(const char *big, const char *little, size_t len)
{
	size_t	big_len;
	size_t	little_len;
	int		cmp;

	if (!len && !big)
		return (NULL);
	big_len = wati_strlen(big);
	little_len = wati_strlen(little);
	if (len < little_len || big_len < little_len)
		return (NULL);
	if (big_len < little_len)
		len = big_len - little_len;
	else
		len = len - little_len;
	cmp = wati_strncmp(big, little, little_len);
	while (len > 0 && cmp)
	{
		len--;
		big++;
		cmp = wati_strncmp(big, little, little_len);
	}
	if (!cmp)
		return ((char *)big);
	return (NULL);
}

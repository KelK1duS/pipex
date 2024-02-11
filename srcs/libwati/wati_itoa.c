/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wati_itoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 13:44:54 by bedarenn          #+#    #+#             */
/*   Updated: 2024/01/21 15:45:26 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libwati.h>
#include <stdlib.h>

static size_t	wati_int_len(int n)
{
	if (n < 10 && n > -10)
		return (1);
	return (wati_int_len(n / 10) + 1);
}

static void	wati_uitoa(char *str, unsigned int n)
{
	if (n > 0)
	{
		*str = n % 10 + 48;
		wati_uitoa(str - 1, n / 10);
	}
}

char	*wati_itoa(int n)
{
	char	*str;
	size_t	n_len;

	n_len = wati_int_len(n);
	if (n < 0)
		n_len++;
	str = malloc(sizeof(char) * (n_len + 1));
	if (!str)
		return (NULL);
	str[n_len] = '\0';
	if (n < 0)
	{
		*str = '-';
		wati_uitoa(str + n_len - 1, -n);
	}
	else if (n == 0)
		*str = '0';
	else
		wati_uitoa(str + n_len - 1, n);
	return (str);
}

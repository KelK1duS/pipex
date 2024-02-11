/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wati_putnbr_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 19:38:55 by bedarenn          #+#    #+#             */
/*   Updated: 2024/01/21 16:25:55 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libwati.h>

static void	wati_putunbr_fd(unsigned int n, int fd)
{
	if (n > 0)
	{
		wati_putunbr_fd(n / 10, fd);
		wati_putchar_fd(n % 10 + 48, fd);
	}
}

void	wati_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		wati_putchar_fd('-', fd);
		wati_putunbr_fd(-n, fd);
	}
	else if (n == 0)
		wati_putchar_fd('0', fd);
	else
		wati_putunbr_fd(n, fd);
}

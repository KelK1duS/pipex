/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wati_printf_utils_nbr.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 22:34:23 by bedarenn          #+#    #+#             */
/*   Updated: 2024/01/21 16:20:12 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libwati.h>
#include <unistd.h>

static int	wati_printf_nbr_base_fd(size_t n, char *base,
	size_t size, int fd)
{
	if (n > 0)
		return (wati_printf_nbr_base_fd(n / size, base, size, fd)
			+ wati_printf_char_fd(base[n % size], fd));
	return (0);
}

int	wati_printf_unbr_base_fd(unsigned int n, char *base, size_t size, int fd)
{
	if (n == 0)
		return (wati_printf_char_fd('0', fd));
	return (wati_printf_nbr_base_fd(n, base, size, fd));
}

int	wati_printf_usnbr_base_fd(size_t n, char *base, size_t size, int fd)
{
	if (n == 0)
		return (write(fd, "0", 1));
	return (wati_printf_nbr_base_fd(n, base, size, fd));
}

int	wati_printf_snbr_base_fd(int n, char *base, size_t size, int fd)
{
	if (n == 0)
		return (wati_printf_char_fd('0', fd));
	if (n < 0)
	{
		return (wati_printf_char_fd('-', fd)
			+ wati_printf_nbr_base_fd((unsigned int)-n, base, size, fd));
	}
	return (wati_printf_nbr_base_fd(n, base, size, fd));
}

int	wati_printf_ptr_fd(void *ptr, int fd)
{
	if (!ptr)
		return (write(fd, "(nil)", 5));
	return (write(fd, "0x", 2)
		+ wati_printf_nbr_base_fd((size_t)ptr, "0123456789abcdef", 16, fd));
}

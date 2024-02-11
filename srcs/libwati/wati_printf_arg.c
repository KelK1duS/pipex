/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wati_printf_arg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 21:30:28 by bedarenn          #+#    #+#             */
/*   Updated: 2024/01/21 16:25:22 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libwati.h>
#include <unistd.h>

int	wati_printf_arg_str(int fd, char format, va_list arg)
{
	if (format == 'c')
		return (wati_printf_char_fd(va_arg(arg, int), fd));
	else if (format == 's')
		return (wati_printf_str_fd(va_arg(arg, char *), fd));
	return (-1);
}

int	wati_printf_arg_nbr(int fd, char format, va_list arg)
{
	if (format == 'p')
		return (wati_printf_ptr_fd(va_arg(arg, void *), fd));
	else if (format == 'd' || format == 'i')
		return (wati_printf_snbr_base_fd(va_arg(arg, int),
				"0123456789", 10, fd));
	else if (format == 'u')
		return (wati_printf_unbr_base_fd(va_arg(arg, unsigned int),
				"0123456789", 10, fd));
	else if (format == 'x')
		return (wati_printf_unbr_base_fd(va_arg(arg, unsigned int),
				"0123456789abcdef", 16, fd));
	else if (format == 'X')
		return (wati_printf_unbr_base_fd(va_arg(arg, unsigned int),
				"0123456789ABCDEF", 16, fd));
	else if (format == 'z')
		return (wati_printf_usnbr_base_fd(va_arg(arg, size_t),
				"0123456789", 10, fd));
	return (-1);
}

int	wati_printf_arg(int fd, char format, va_list arg)
{
	int	r;

	r = wati_printf_arg_str(fd, format, arg);
	if (r != -1)
		return (r);
	r = wati_printf_arg_nbr(fd, format, arg);
	if (r != -1)
		return (r);
	else if (format == '%')
		return (write(fd, "%", 1));
	else if (format)
		return (write(fd, "%", 1) + write(fd, &format, 1));
	return (-1);
}

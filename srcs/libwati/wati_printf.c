/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wati_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:51:32 by bedarenn          #+#    #+#             */
/*   Updated: 2024/01/21 16:25:36 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libwati.h>
#include <unistd.h>

int	wati_vfprintf(int fd, const char *format, va_list arg)
{
	int	size;
	int	r;

	if (!format)
		return (-1);
	size = 0;
	while (*format)
	{
		if (*format == '%')
		{
			r = wati_printf_arg(fd, format[1], arg);
			if (r < 0)
				return (-1);
			format++;
			size += r;
		}
		else
		{
			write(fd, format, 1);
			size++;
		}
		format++;
	}
	return (size);
}

int	wati_printf(const char *format, ...)
{
	va_list	arg;
	int		count;

	va_start(arg, format);
	count = wati_vprintf(format, arg);
	va_end(arg);
	return (count);
}

int	wati_fprintf(int fd, const char *format, ...)
{
	va_list	arg;
	int		count;

	va_start(arg, format);
	count = wati_vfprintf(fd, format, arg);
	va_end(arg);
	return (count);
}

int	wati_vprintf(const char *format, va_list arg)
{
	return (wati_vfprintf(1, format, arg));
}

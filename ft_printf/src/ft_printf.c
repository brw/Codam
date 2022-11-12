/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   ft_printf.c                                       :+:    :+:             */
/*                                                    +:+                     */
/*   By: bvan-den <bvan-den@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2022/11/10 20:47:52 by bvan-den      #+#    #+#                 */
/*   Updated: 2022/11/10 20:49:01 by bvan-den      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"
#include <libft.h>
#include <stdarg.h>
#include <unistd.h>

static ssize_t	print(const char c, va_list args)
{
	if (c == '%')
		return (print_char('%'));
	else if (c == 'c')
		return (print_char((unsigned char)va_arg(args, int)));
	else if (c == 's')
		return (print_str(va_arg(args, const char *)));
	else if (c == 'd' || c == 'i')
		return (print_nbr(va_arg(args, int), "0123456789", 10));
	else if (c == 'u')
		return (print_unbr(va_arg(args, unsigned int), "0123456789", 10));
	else if (c == 'x')
		return (print_unbr(va_arg(args, unsigned int), "0123456789abcdef", 16));
	else if (c == 'X')
		return (print_unbr(va_arg(args, unsigned int), "0123456789ABCDEF", 16));
	else if (c == 'p')
		return (print_ptr(va_arg(args, unsigned long)));
	return (-1);
}

int	ft_vprintf(const char *fmt, va_list args)
{
	ssize_t	written;
	ssize_t	total_written;

	total_written = 0;
	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt++;
			if (!*fmt)
				return ((int)total_written);
			written = print(*fmt, args);
			if (written == -1)
				total_written += print_char(*fmt);
			else
				total_written += written;
		}
		else
			total_written += print_char(*fmt);
		fmt++;
	}
	return ((int)total_written);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	int		total_written;

	va_start(args, fmt);
	total_written = ft_vprintf(fmt, args);
	va_end(args);
	return (total_written);
}

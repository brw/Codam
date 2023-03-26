/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   ft_printf.c                                       :+:    :+:             */
/*                                                    +:+                     */
/*   By: bvan-den <bvan-den@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2022/11/10 20:47:52 by bvan-den      #+#    #+#                 */
/*   Updated: 2023/03/26 18:51:24 by bvan-den      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"
#include <libft.h>
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

static ssize_t	print(const char c, va_list args)
{
	if (c == '%')
		return (print_char('%'));
	if (c == 'c')
		return (print_char((unsigned char)va_arg(args, int)));
	if (c == 's')
		return (print_str(va_arg(args, const char *)));
	if (c == 'd' || c == 'i')
		return (print_nbr(va_arg(args, int), "0123456789", 10));
	if (c == 'u')
		return (print_unbr(va_arg(args, unsigned int), "0123456789", 10));
	if (c == 'x')
		return (print_unbr(va_arg(args, unsigned int), "0123456789abcdef", 16));
	if (c == 'X')
		return (print_unbr(va_arg(args, unsigned int), "0123456789ABCDEF", 16));
	if (c == 'p')
		return (print_ptr(va_arg(args, unsigned long)));
	return (print_char(c));
}

int	ft_vprintf(const char *fmt, va_list args)
{
	ssize_t	total_written;
	char	*next;

	total_written = 0;
	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt++;
			if (!*fmt)
				return ((int)total_written);
			total_written += print(*fmt, args);
			fmt++;
		}
		else
		{
			next = ft_strchr(fmt, '%');
			if (!next)
				next = (char *)fmt + 1;
			total_written += write(STDOUT_FILENO, fmt, (size_t)(next - fmt));
			fmt = next;
		}
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

int	ft_vdprintf(int fd, const char *fmt, va_list args)
{
	ssize_t	total_written;
	char	*next;

	total_written = 0;
	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt++;
			if (!*fmt)
				return ((int)total_written);
			total_written += print(*fmt, args);
			fmt++;
		}
		else
		{
			next = ft_strchr(fmt, '%');
			if (!next)
				next = (char *)fmt + 1;
			total_written += write(fd, fmt, (size_t)(next - fmt));
			fmt = next;
		}
	}
	return ((int)total_written);
}

int	ft_dprintf(int fd, const char *fmt, ...)
{
	va_list	args;
	int		total_written;

	va_start(args, fmt);
	total_written = ft_vdprintf(fd, fmt, args);
	va_end(args);
	return (total_written);
}

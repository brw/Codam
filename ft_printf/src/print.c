/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   print.c                                           :+:    :+:             */
/*                                                    +:+                     */
/*   By: bvan-den <bvan-den@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2022/11/10 20:48:00 by bvan-den      #+#    #+#                 */
/*   Updated: 2023/06/01 20:00:14 by bvan-den      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdarg.h>
#include <unistd.h>

ssize_t	print_char(int fd, int c)
{
	return (write(fd, &c, 1));
}

ssize_t	print_str(int fd, const char *str)
{
	if (!str)
		return (write(fd, "(null)", 6));
	return (write(fd, str, ft_strlen(str)));
}

ssize_t	print_unbr(int fd, unsigned long num, const char *symbols,
		unsigned int base)
{
	ssize_t	written;

	written = 0;
	if (num >= base)
		written += print_unbr(fd, num / base, symbols, base);
	written += print_char(fd, symbols[num % base]);
	return (written);
}

ssize_t	print_nbr(int fd, long num, const char *symbols, unsigned int base)
{
	ssize_t	written;

	written = 0;
	if (num < 0)
	{
		written += print_char(fd, '-');
		num *= -1;
	}
	return (print_unbr(fd, (unsigned long)num, symbols, base) + written);
}

ssize_t	print_ptr(int fd, unsigned long p)
{
	write(fd, "0x", 2);
	return (print_unbr(fd, p, "0123456789abcdef", 16) + 2);
}

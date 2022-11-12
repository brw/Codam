/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   print.c                                           :+:    :+:             */
/*                                                    +:+                     */
/*   By: bvan-den <bvan-den@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2022/11/10 20:48:00 by bvan-den      #+#    #+#                 */
/*   Updated: 2022/11/10 20:48:33 by bvan-den      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdarg.h>
#include <unistd.h>

ssize_t	print_char(int c)
{
	return (write(STDOUT_FILENO, &c, 1));
}

ssize_t	print_str(const char *str)
{
	size_t	len;

	if (!str)
		return (write(STDOUT_FILENO, "(null)", 6));
	len = ft_strlen(str);
	return (write(STDOUT_FILENO, str, len));
}

ssize_t	print_unbr(unsigned long num, const char *symbols, unsigned int base)
{
	ssize_t	written;

	written = 0;
	if (num >= base)
		written += print_unbr(num / base, symbols, base);
	written += print_char(symbols[num % base]);
	return (written);
}

ssize_t	print_nbr(long c, const char *symbols, unsigned int base)
{
	ssize_t	written;

	written = 0;
	if (c < 0)
	{
		written += print_char('-');
		c *= -1;
	}
	return (print_unbr((unsigned long)c, symbols, base) + written);
}

ssize_t	print_ptr(unsigned long p)
{
	write(STDOUT_FILENO, "0x", 2);
	return (print_unbr(p, "0123456789abcdef", 16) + 2);
}

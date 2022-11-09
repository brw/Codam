#include <libft.h>
#include <stdarg.h>
#include <unistd.h>

static ssize_t	print_char(int c)
{
	return (write(STDOUT_FILENO, &c, 1));
}

static ssize_t	print_str(const char *str)
{
	size_t	len;

	if (!str)
		return (write(STDOUT_FILENO, "(null)", 6));
	len = ft_strlen(str);
	return (write(STDOUT_FILENO, str, len));
}

static ssize_t	print_unbr(unsigned long num, const char *symbols, unsigned int base)
{
	ssize_t	written;

	written = 0;
	if (num >= base)
		written += print_unbr(num / base, symbols, base);
	written += print_char(symbols[num % base]);
	return (written);
}

static ssize_t	print_nbr(long c, const char *symbols, unsigned int base)
{
	ssize_t	written;

	written = 0;
	if (c < 0)
	{
		written += print_char('-');
		c *= -1;
	}
	return (print_unbr((unsigned long) c, symbols, base) + written);
}

static ssize_t	print_ptr(unsigned long p)
{
	write(STDOUT_FILENO, "0x", 2);
	return (print_unbr(p, "0123456789abcdef", 16) + 2);
}

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

int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	ssize_t	written;
	ssize_t	total_written;

	va_start(args, fmt);
	total_written = 0;
	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt++;
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
	va_end(args);
	return ((int)total_written);
}

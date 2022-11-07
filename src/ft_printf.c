#include <libft.h>
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

static int	print_char(unsigned char c)
{
	return ((int)write(1, &c, STDOUT_FILENO));
}

static int	print_str(char *c)
{
	size_t	len;

	if (!c)
		return ((int)write(1, "(null)", 6));
	len = ft_strlen(c);
	return ((int)write(1, c, len));
}

static int	print_nbr(int c)
{
	unsigned int	num;
	int				written;

	written = 0;
	if (c < 0)
	{
		written += print_char('-');
		num = (unsigned int)(c * -1);
	}
	else
		num = (unsigned int)c;
	if (num > 9)
		written += print_nbr(num / 10);
	written += print_char(num % 10 + '0');
	return (written);
}

static int	print_unbr(unsigned int num)
{
	int	written;

	written = 0;
	if (num > 9)
		written += print_unbr(num / 10);
	written += print_char(num % 10 + '0');
	return (written);
}

static int	print_hex(unsigned long num, int uppercase)
{
	int				written;
	unsigned char	cur;
	unsigned char	offset;

	written = 0;
	if (num > 16)
		written += print_hex(num / 16, uppercase);
	if (uppercase)
		offset = '7';
	else
		offset = 'W';
	if (num == 16)
		written += print_str("10");
	else
	{
		cur = num % 16;
		if (cur > 9)
			written += print_char(cur + offset);
		else
			written += print_char(cur + '0');
	}
	return (written);
}

static int	print_hex_lower(unsigned int num)
{
	return (print_hex(num, 0));
}

static int	print_hex_upper(unsigned int num)
{
	return (print_hex(num, 1));
}

static int	print_pointer(unsigned long p)
{
	write(1, "0x", 2);
	return (print_hex(p, 0) + 2);
}

static int	print(const char *fmt, va_list args)
{
	if (*fmt == '%')
		return (print_char('%'));
	else if (*fmt == 'c')
		return (print_char((unsigned char)va_arg(args, int)));
	else if (*fmt == 's')
		return (print_str(va_arg(args, char *)));
	else if (*fmt == 'd' || *fmt == 'i')
		return (print_nbr(va_arg(args, int)));
	else if (*fmt == 'u')
		return (print_unbr(va_arg(args, unsigned int)));
	else if (*fmt == 'x')
		return (print_hex_lower(va_arg(args, unsigned int)));
	else if (*fmt == 'X')
		return (print_hex_upper(va_arg(args, unsigned int)));
	else if (*fmt == 'p')
		return (print_pointer(va_arg(args, unsigned long)));
	return (-1);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	int		written;
	int		total_written;

	va_start(args, fmt);
	total_written = 0;
	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt++;
			written = print(fmt, args);
			if (written == -1)
				total_written += write(1, fmt, 1);
			else
				total_written += written;
		}
		else
			total_written += write(1, fmt, 1);
		fmt++;
	}
	va_end(args);
	return (total_written);
}

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;

	if (n == 0)
		return (0);
	str = (unsigned char *)s;
	while(*str != (unsigned char)c)
	{
		n--;
		if (n == 0)
			return (0);
		str++;
	}
	return (str);
}

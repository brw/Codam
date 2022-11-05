#include <libft.h>
#include <unistd.h>

int	ft_printf()
{
	write(1, ft_strdup("a"), 2);
	return (0);
}

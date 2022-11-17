#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	size_t	i;
	char	*line;

	fd = open("test2.txt", O_RDONLY);
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		line = get_next_line(fd);
		i++;
	}
}

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	size_t	i;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		line = get_next_line(fd);
		printf("line %lu: %s", i, line);
		i++;
	}
}

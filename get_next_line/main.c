#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	int		fd;
	size_t	i;
	char	*line;

	fd = open("variable_nls.txt", O_RDONLY);
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		printf("%lu: %s", i, line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
}

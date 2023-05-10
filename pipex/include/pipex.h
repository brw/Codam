#ifndef PIPEX_H

typedef struct pipex
{
	int	infile_fd;
	int	outfile_fd;
	int	pipe_end;
}		t_pipex;

# define PIPEX_H
#endif

#ifndef PIPEX_H

typedef struct s_pipex
{
	char	*infile;
	char	*outfile;
	int		in_fd;
	int		out_fd;
	int		pipe_fd[2];
}			t_pipex;

# define PIPEX_H
#endif

#ifndef PIPEX_H
# define PIPEX_H

typedef struct s_pipex
{
	char	*program;
	char	**paths;
	char	*infile;
	char	*outfile;
	int		in_fd;
	int		out_fd;
	int		pipe_fd[2];
}			t_pipex;

#endif

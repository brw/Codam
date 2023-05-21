#ifndef PIPEX_H
# define PIPEX_H

typedef struct ctx
{
	char				*program_name;
	char				**paths;
	char				*infile;
	char				*outfile;
	int					pipe_fd[2];
}						t_context;

typedef enum fd_or_filename
{
	FD,
	FILENAME
}						t_fd_or_filename;

typedef struct redir
{
	t_fd_or_filename	type;
	union
	{
		int				fd;
		char			*filename;
	};
}						t_redir;

#endif

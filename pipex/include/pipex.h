#ifndef PIPEX_H
# define PIPEX_H

# include <stdbool.h>

typedef enum fd_or_filename
{
	FD,
	FILENAME
}						t_fd_or_filename;

typedef enum order
{
	FIRST,
	MIDDLE,
	LAST
}						t_order;

typedef struct redir
{
	t_fd_or_filename	type;
	union
	{
		int				fd;
		char			*filename;
	};
}						t_redir;

typedef struct ctx
{
	char				*program_name;
	bool				heredoc;
	char				**paths;
	char				*infile;
	char				*outfile;
	int					pipe_fd[2];
	t_redir				in;
	t_redir				out;
}						t_context;

#endif

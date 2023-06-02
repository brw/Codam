/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   pipex_bonus.h                                     :+:    :+:             */
/*                                                    +:+                     */
/*   By: bvan-den <bvan-den@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2023/06/02 02:43:18 by bvan-den      #+#    #+#                 */
/*   Updated: 2023/06/02 02:43:19 by bvan-den      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <errno.h>
# include <fcntl.h>
# include <ft_printf.h>
# include <get_next_line.h>
# include <libft.h>
# include <stdbool.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# ifdef linux
#  include <sys/wait.h>
# endif

extern char				**environ;

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
	int					cmd_i;
	t_redir				in;
	t_redir				out;
}						t_context;

void					handle_args(t_context *ctx, int argc, char **argv);
void					setup_redirs(t_context *ctx, int argc, char **argv);
int						spawn_child(t_context *ctx, char *cmdstr);
void					setup_io(t_context *ctx);
void					exit_error(t_context *ctx, char *obj, char *msg,
							int exit_code);
void					free_array(char **args);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   handle_fds.c                                      :+:    :+:             */
/*                                                    +:+                     */
/*   By: bvan-den <bvan-den@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2023/06/01 21:55:41 by bvan-den      #+#    #+#                 */
/*   Updated: 2023/06/01 21:55:41 by bvan-den      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

int	get_fd(t_context *ctx, t_redir *arg, int flags, mode_t mode)
{
	int	fd;

	if (arg->type == FILENAME)
	{
		fd = open(arg->filename, flags, mode);
		if (fd == -1)
			exit_error(ctx, arg->filename, NULL, errno);
		return (fd);
	}
	else
		return (arg->fd);
}

void	setup_io(t_context *ctx)
{
	int	in_fd;
	int	out_fd;

	in_fd = get_fd(ctx, &ctx->in, O_RDONLY, 0);
	out_fd = get_fd(ctx, &ctx->out, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (dup2(in_fd, STDIN_FILENO) == -1)
	{
		close(in_fd);
		close(out_fd);
		exit_error(ctx, "dup2", NULL, errno);
	}
	close(in_fd);
	if (dup2(out_fd, STDOUT_FILENO) == -1)
	{
		close(out_fd);
		exit_error(ctx, "dup2", NULL, errno);
	}
	close(out_fd);
}

void	setup_redirs(t_context *ctx, int argc, char **argv)
{
	if (ctx->cmd_i == 2)
	{
		ctx->in.type = FILENAME;
		ctx->in.filename = argv[1];
	}
	else
	{
		ctx->in.type = FD;
		ctx->in.fd = ctx->pipe_fd[0];
		close(ctx->pipe_fd[1]);
	}
	if (ctx->cmd_i == argc - 2)
	{
		ctx->out.type = FILENAME;
		ctx->out.filename = argv[argc - 1];
	}
	else
	{
		if (pipe(ctx->pipe_fd) == -1)
			exit_error(ctx, "failed to create pipe", NULL, errno);
		ctx->out.type = FD;
		ctx->out.fd = ctx->pipe_fd[1];
	}
}

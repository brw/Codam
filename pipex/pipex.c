#include <errno.h>
#include <fcntl.h>
#include <ft_printf.h>
#include <libft.h>
#include <pipex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

extern char	**environ;

// TODO:
// - error handling for fork()
// - write error handling
// - dup error handling
// - more error handling
// - fix ft_fprintf to work with stderr
// - handle heredoc
// - when supplying a path supply only the binary name argv[0] to execve

void	exit_error(t_context *ctx, char *obj, char *msg, int exit_code)
{
	if (!msg)
		msg = strerror(errno);
	if (obj)
		fprintf(stderr, "%s: %s: %s\n", ctx->program_name, obj, msg);
	else
		fprintf(stderr, "%s: %s\n", ctx->program_name, msg);
	if (exit_code)
		exit(exit_code);
}

char	*get_path_env(char **env)
{
	while (*env)
	{
		if (ft_strncmp(*env, "PATH=", 5) == 0)
			return (*env + 5);
		env++;
	}
	return (NULL);
}

char	*get_cmd_path(char *cmd, t_context *ctx)
{
	char	*try_path;
	int		i;

	if (ft_strchr(cmd, '/'))
	{
		if (access(cmd, F_OK | X_OK) == 0)
			return (cmd);
		else
			exit_error(ctx, cmd, NULL, 127);
	}
	i = 0;
	while (ctx->paths && ctx->paths[i])
	{
		try_path = ft_strjoin(ft_strjoin(ctx->paths[i], "/"), cmd);
		if (access(try_path, F_OK) == 0)
		{
			if (access(try_path, X_OK) == -1)
				exit_error(ctx, try_path, NULL, 126);
			return (try_path);
		}
		free(try_path);
		i++;
	}
	exit_error(ctx, cmd, "command not found", 127);
	return (NULL);
}

int	get_fd(t_context *ctx, t_redir *arg, int flags, mode_t mode)
{
	int	fd;

	if (arg->type == FILENAME)
	{
		fd = open(arg->filename, flags, mode);
		if (fd == -1)
			exit_error(ctx, arg->filename, NULL, 1);
		return (fd);
	}
	else
		return (arg->fd);
}

void	setup_io(t_context *ctx)
{
	int	in_fd;
	int	out_fd;

	if (ctx->in->type == FD)
		close(ctx->pipe_fd[1]);
	if (ctx->out->type == FD)
		close(ctx->pipe_fd[0]);
	in_fd = get_fd(ctx, ctx->in, O_RDONLY, 0);
	out_fd = get_fd(ctx, ctx->out, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	dup2(in_fd, STDIN_FILENO);
	close(in_fd);
	dup2(out_fd, STDOUT_FILENO);
	close(out_fd);
}

void	execute_command(t_context *ctx, char *cmdstr)
{
	char	**args;
	char	*cmd;

	args = ft_split_args(cmdstr);
	cmd = get_cmd_path(args[0], ctx);
	execve(cmd, args, environ);
	exit_error(ctx, cmd, NULL, 1);
}

int	spawn_child(t_context *ctx, char *cmdstr)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		setup_io(ctx);
		execute_command(ctx, cmdstr);
	}
	return (pid);
}

void	setup_redirs(t_context *ctx, int i, int argc, char **argv)
{
	if (i == 2)
	{
		ctx->in->type = FILENAME;
		ctx->in->filename = argv[1];
	}
	else
	{
		ctx->in->type = FD;
		ctx->in->fd = ctx->pipe_fd[0];
	}
	if (i == argc - 2)
	{
		ctx->out->type = FILENAME;
		ctx->out->filename = argv[argc - 1];
	}
	else
	{
		pipe(ctx->pipe_fd);
		ctx->out->type = FD;
		ctx->out->fd = ctx->pipe_fd[1];
	}
}

int	main(int argc, char **argv)
{
	t_context	ctx;
	pid_t		last_pid;
	int			i;
	int			status;

	// if (argc != 5)
	// 	exit_error(&ctx, NULL, "Needs exactly 4 arguments", 1);
	ctx.program_name = argv[0];
	if (argc < 5)
		exit_error(&ctx, NULL, "Needs 4 or more arguments", 1);
	ctx.paths = ft_split(get_path_env(environ), ':');
	i = 2;
	while (i < argc - 1)
	{
		setup_redirs(&ctx, i, argc, argv);
		last_pid = spawn_child(&ctx, argv[i]);
		if (ctx.in->type == FD)
			close(ctx.in->fd);
		if (ctx.out->type == FD)
			close(ctx.out->fd);
		i++;
	}
	waitpid(last_pid, &status, 0);
	while (wait(NULL) != -1)
		continue ;
	exit(WEXITSTATUS(status));
}

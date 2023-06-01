#include <errno.h>
#include <fcntl.h>
#include <ft_printf.h>
#include <get_next_line.h>
#include <libft.h>
#include <pipex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#ifdef linux
# include <sys/wait.h>
#endif

#define HEREDOC_TMP_FILE "/tmp/pipex_heredoc_tmp"

extern char	**environ;

// TODO:
// - when supplying a path supply only the binary name argv[0] to execve

void	free_array(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		free(args[i]);
		args[i] = NULL;
		i++;
	}
	free(args);
	args = NULL;
}

void	exit_error(t_context *ctx, char *obj, char *msg, int exit_code)
{
	if (!msg)
		msg = strerror(errno);
	if (obj)
		ft_dprintf(STDERR_FILENO, "%s: %s: %s\n", ctx->program_name, obj, msg);
	else
		ft_dprintf(STDERR_FILENO, "%s: %s\n", ctx->program_name, msg);
	if (ctx->paths)
		free_array(ctx->paths);
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

char	*create_try_path(t_context *ctx, int i, char *cmd)
{
	char	*tmp;
	char	*str;

	tmp = ft_strjoin(ctx->paths[i], "/");
	if (!tmp)
		exit_error(ctx, "ft_strjoin", NULL, errno);
	str = ft_strjoin(tmp, cmd);
	free(tmp);
	if (!str)
		exit_error(ctx, "ft_strjoin", NULL, errno);
	return (str);
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
		try_path = create_try_path(ctx, i, cmd);
		if (access(try_path, F_OK) == 0)
		{
			free_array(ctx->paths);
			if (access(try_path, X_OK) == 0)
				return (try_path);
			exit_error(ctx, try_path, NULL, 126);
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

void	execute_command(t_context *ctx, char *cmdstr)
{
	char	**args;
	char	*cmd;

	args = ft_split_args(cmdstr);
	if (!args)
		exit_error(ctx, "ft_split_args", NULL, errno);
	cmd = get_cmd_path(args[0], ctx);
	execve(cmd, args, environ);
	exit_error(ctx, cmd, NULL, errno);
}

int	spawn_child(t_context *ctx, char *cmdstr)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		exit_error(ctx, "fork", NULL, errno);
	if (pid == 0)
	{
		setup_io(ctx);
		execute_command(ctx, cmdstr);
	}
	if (ctx->out.type == FD)
		close(ctx->out.fd);
	return (pid);
}

void	setup_redirs(t_context *ctx, int i, int argc, char **argv)
{
	if (i == 2)
	{
		ctx->in.type = FILENAME;
		ctx->in.filename = argv[1];
	}
	else if (!ctx->heredoc || (ctx->heredoc && i != 3))
	{
		ctx->in.type = FD;
		ctx->in.fd = ctx->pipe_fd[0];
		close(ctx->pipe_fd[1]);
	}
	if (i == argc - 2)
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

void	handle_heredoc(t_context *ctx, int argc, char **argv)
{
	int		tmp_fd;
	char	*line;
	char	*delim;

	if (argc < 6)
		exit_error(ctx, NULL, "Needs >=2 commands and output file", 1);
	tmp_fd = open(HEREDOC_TMP_FILE, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (tmp_fd == -1)
		exit_error(ctx, HEREDOC_TMP_FILE, NULL, errno);
	delim = argv[2];
	while (true)
	{
		ft_printf("> ");
		line = get_next_line(STDIN_FILENO);
		if (!line || ft_strncmp(line, delim, ft_strlen(delim)) == 0)
		{
			free(line);
			break ;
		}
		ft_putstr_fd(line, tmp_fd);
		free(line);
	}
	close(tmp_fd);
	ctx->in.type = FILENAME;
	ctx->in.filename = HEREDOC_TMP_FILE;
}

int	main(int argc, char **argv)
{
	t_context	ctx;
	pid_t		last_pid;
	int			cmd_i;
	int			status;

	// if (argc != 5)
	// 	exit_error(&ctx, NULL, "Needs exactly 4 arguments", 1);
	ctx.program_name = argv[0];
	ctx.paths = NULL;
	ctx.heredoc = false;
	if (argc > 1 && ft_strncmp(argv[1], "here_doc", 9) == 0)
	{
		handle_heredoc(&ctx, argc, argv);
		ctx.heredoc = true;
		cmd_i = 3;
	}
	else
	{
		if (argc < 5)
			exit_error(&ctx, NULL, "Needs >=2 commands and output file", 1);
		cmd_i = 2;
	}
	ctx.paths = ft_split(get_path_env(environ), ':');
	while (cmd_i < argc - 1)
	{
		setup_redirs(&ctx, cmd_i, argc, argv);
		last_pid = spawn_child(&ctx, argv[cmd_i]);
		if (ctx.in.type == FD)
			close(ctx.in.fd);
		if (ctx.out.type == FD)
			close(ctx.out.fd);
		cmd_i++;
	}
	waitpid(last_pid, &status, 0);
	while (wait(NULL) != -1)
		continue ;
	free_array(ctx.paths);
	if (ctx.heredoc == true)
		unlink("/tmp/pipex_heredoc_tmp");
	exit(WEXITSTATUS(status));
}

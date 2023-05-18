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
// - when supplying a path supply only the binary name argv[0] to execve
// - figure out why it hangs with /dev/urandom
// - error handling for fork()
// - handle access denied
//	- infile/outfile
// - write error handling
// - dup error handling
// - more error handling
// - fix ft_fprintf to work with stderr
// - handle escaping with backticks of spaces and quotes and everything I guess? Maybe?
// - handle semicolons, && and || (this is probably too close to Minishell)

void	exit_error(char *obj, char *msg, char exit_code)
{
	if (!msg)
		msg = strerror(errno);
	if (obj)
		fprintf(stderr, "pipex: %s: %s\n", obj, msg);
	else
		fprintf(stderr, "pipex: %s\n", msg);
	if (exit_code)
		exit(exit_code);
}

void	file_error(char *filename)
{
	char	*msg;

	msg = ft_strjoin("pipex: ", filename);
	if (!msg)
		return ;
	perror(msg);
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

char	*get_cmd_path(char *cmd, char **paths)
{
	char	*try_path;

	if (ft_strchr(cmd, '/'))
	{
		if (access(cmd, F_OK | X_OK) == 0)
			return (cmd);
		else
			exit_error(cmd, NULL, 127);
	}
	while (paths && *paths)
	{
		try_path = ft_strjoin(ft_strjoin(*paths, "/"), cmd);
		if (access(try_path, F_OK) == 0)
		{
			if (access(try_path, X_OK) == -1)
				exit_error(try_path, NULL, 126);
			return (try_path);
		}
		free(try_path);
		paths++;
	}
	exit_error(cmd, "command not found", 127);
	return (NULL);
}

int	run_cmd(char *cmdstr, int in_fd, int out_fd, int extra_fd, char **paths)
{
	char	**args;
	char	*cmd;
	pid_t	pid;


	pid = fork();
	if (pid == 0)
	{
		args = ft_split_args(cmdstr);
		cmd = get_cmd_path(args[0], paths);
		if (cmd == NULL)
			exit(1);
		fprintf(stderr, "out_fd - in_fd child '%s': %d - %d\n", cmd, out_fd, in_fd);
		dup2(in_fd, STDIN_FILENO);
		close(in_fd);
		dup2(out_fd, STDOUT_FILENO);
		close(extra_fd);
		fprintf(stderr, "closed in_fd and extra_fd in child %s: %d - %d\n", cmd, in_fd, extra_fd);
		close(out_fd);
		fprintf(stderr, "closed out_fd in child %s: %d: \n", cmd, out_fd);
		execve(cmd, args, environ);
		exit_error(cmd, NULL, 1);
	}
	return (pid);
}

int	main(int argc, char **argv)
{
	char	**paths;
	char	*filename[2];
	int		pipe_fd[2];
	int		in_fd;
	int		out_fd;
	int		last_pid;
	int		status;
	int		i;

	// if (argc != 5)
	// 	exit_error(NULL, "Needs exactly 4 arguments", 1);
	if (argc < 5)
		exit_error(NULL, "Needs 4 or more arguments", 1);
	filename[0] = argv[1];
	in_fd = open(filename[0], O_RDONLY);
	if (in_fd == -1)
		file_error(filename[0]);
	filename[1] = argv[argc - 1];
	out_fd = open(filename[1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (out_fd == -1)
		file_error(filename[1]);
	paths = ft_split(get_path_env(environ), ':');
	i = 2;
	while (i < argc - 1)
	{
		if (i == argc - 2)
			pipe_fd[1] = out_fd;
		else
			pipe(pipe_fd);
		fprintf(stderr, "in_fd: %d, pipe_fd[0]: %d, pipe_fd[1]: %d\n", in_fd, pipe_fd[0], pipe_fd[1]);
		fprintf(stderr, "running command\n");
		last_pid = run_cmd(argv[i], in_fd, pipe_fd[1], pipe_fd[0], paths);
		close(in_fd);
		fprintf(stderr, "closed in_fd: %d\n", in_fd);
		close(pipe_fd[1]);
		fprintf(stderr, "closed pipe_fd[1]: %d\n", pipe_fd[1]);
		in_fd = pipe_fd[0];
		fprintf(stderr, "set in_fd to %d\n", pipe_fd[0]);
		i++;
	}
	close(out_fd);
	waitpid(last_pid, &status, 0);
	while (wait(NULL) != -1)
		continue ;
	exit(WEXITSTATUS(status));
}

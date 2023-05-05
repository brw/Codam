#include <errno.h>
#include <fcntl.h>
#include <ft_printf.h>
#include <libft.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

extern char	**environ;

// TODO:
// - figure out why it hangs with /dev/urandom
// - error handling for fork()
// - handle access denied
//	- infile/outfile
// - write error handling
// - dup error handling
// - more error handling

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

	if (cmd[0] == '/' || (cmd[0] == '.' && cmd[1] == '/'))
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

int	run_cmd(char *cmdstr, int in_fd, int out_fd, char **paths)
{
	char	**args;
	char	*cmd;
	pid_t	pid;

	fprintf(stderr, "in: %d, out: %d\n", in_fd, out_fd);
	pid = fork();
	if (pid == 0)
	{
		args = ft_split_args(cmdstr);
		cmd = get_cmd_path(args[0], paths);
		if (cmd == NULL)
			exit(1);
		dup2(in_fd, STDIN_FILENO);
		close(in_fd);
		dup2(out_fd, STDOUT_FILENO);
		close(out_fd);
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
		last_pid = run_cmd(argv[i], in_fd, pipe_fd[1], paths);
		close(pipe_fd[1]);
		in_fd = pipe_fd[0];
		i++;
	}
	waitpid(last_pid, &status, 0);
	while (wait(NULL) != -1)
		continue ;
	exit(WEXITSTATUS(status));
}

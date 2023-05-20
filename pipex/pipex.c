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
// - handle backslash escaping spaces and quotes and everything I guess? Maybe?
// - handle semicolons, && and || (this is probably too close to Minishell)

void	exit_error(char *program, char *obj, char *msg, int exit_code)
{
	if (!msg)
		msg = strerror(errno);
	if (obj)
		fprintf(stderr, "%s: %s: %s\n", program, obj, msg);
	else
		fprintf(stderr, "%s: %s\n", program, msg);
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

char	*get_cmd_path(char *cmd, t_pipex pipex)
{
	char	*try_path;
	int		i;

	if (ft_strchr(cmd, '/'))
	{
		if (access(cmd, F_OK | X_OK) == 0)
			return (cmd);
		else
			exit_error(pipex.program, cmd, NULL, 127);
	}
	i = 0;
	while (pipex.paths && pipex.paths[i])
	{
		try_path = ft_strjoin(ft_strjoin(pipex.paths[i], "/"), cmd);
		if (access(try_path, F_OK) == 0)
		{
			if (access(try_path, X_OK) == -1)
				exit_error(pipex.program, try_path, NULL, 126);
			return (try_path);
		}
		free(try_path);
		i++;
	}
	exit_error(pipex.program, cmd, "command not found", 127);
	return (NULL);
}

int	run_cmd(char *cmdstr, t_pipex pipex)
{
	char	**args;
	char	*cmd;
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		args = ft_split_args(cmdstr);
		cmd = get_cmd_path(args[0], pipex);
		if (cmd == NULL)
			exit(1);
		dup2(pipex.in_fd, STDIN_FILENO);
		dup2(pipex.pipe_fd[1], STDOUT_FILENO);
		close(pipex.in_fd);
		close(pipex.pipe_fd[0]);
		close(pipex.out_fd);
		execve(cmd, args, environ);
		exit_error(pipex.program, cmd, NULL, errno);
	}
	return (pid);
}

int	main(int argc, char **argv)
{
	t_pipex	pipex;
	pid_t	last_pid;
	int		i;
	int		status;

	// if (argc != 5)
	// 	exit_error(NULL, "Needs exactly 4 arguments", 1);
	pipex.program = argv[0];
	if (argc < 5)
		exit_error(pipex.program, NULL, "Needs 4 or more arguments", 1);
	pipex.infile = argv[1];
	pipex.in_fd = open(pipex.infile, O_RDONLY);
	if (pipex.in_fd == -1)
		file_error(pipex.infile);
	pipex.outfile = argv[argc - 1];
	pipex.out_fd = open(pipex.outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pipex.out_fd == -1)
		exit_error(pipex.program, pipex.outfile, NULL, 1);
	pipex.paths = ft_split(get_path_env(environ), ':');
	i = 2;
	while (i < argc - 1)
	{
		if (i == argc - 2)
			pipex.pipe_fd[1] = pipex.out_fd;
		else
			pipe(pipex.pipe_fd);
		last_pid = run_cmd(argv[i], pipex);
		close(pipex.in_fd);
		close(pipex.pipe_fd[1]);
		pipex.in_fd = pipex.pipe_fd[0];
		i++;
	}
	close(pipex.out_fd);
	waitpid(last_pid, &status, 0);
	while (wait(NULL) != -1)
		continue ;
	exit(WEXITSTATUS(status));
}

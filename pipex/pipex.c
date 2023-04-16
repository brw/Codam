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
// - error handling for fork()
// - handle access denied
//	- commands
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
	while (*paths)
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

int	run_cmd(int nbr, int pipefd[2], char *cmdstr, int file, char **paths)
{
	char	**args;
	char	*cmd;
	pid_t	pid;

	pid = fork();
	if (pid != 0)
		return (pid);
	args = ft_split_args(cmdstr);
	cmd = get_cmd_path(args[0], paths);
	if (cmd == NULL || file == -1)
		exit(1);
	if (nbr == 1)
	{
		dup2(file, STDIN_FILENO);
		dup2(pipefd[1], STDOUT_FILENO);
	}
	else if (nbr == 2)
	{
		dup2(pipefd[0], STDIN_FILENO);
		dup2(file, STDOUT_FILENO);
	}
	close(file);
	close(pipefd[0]);
	close(pipefd[1]);
	execve(cmd, args, environ);
	exit_error(cmd, NULL, 1);
	return (-1);
}

int	main(int argc, char **argv)
{
	char	**paths;
	int		file[2];
	int		pipefd[2];
	int		pid[2];
	int		status;

	if (argc != 5)
		exit_error(NULL, "Needs exactly 4 arguments", 1);
	file[0] = open(argv[1], O_RDONLY);
	if (file[0] == -1)
		file_error(argv[1]);
	file[1] = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (file[1] == -1)
		file_error(argv[4]);
	paths = ft_split(get_path_env(environ), ':');
	pipe(pipefd);
	pid[0] = run_cmd(1, pipefd, argv[2], file[0], paths);
	pid[1] = run_cmd(2, pipefd, argv[3], file[1], paths);
	close(pipefd[0]);
	close(pipefd[1]);
	waitpid(pid[0], NULL, 0);
	waitpid(pid[1], &status, 0);
	exit(WEXITSTATUS(status));
}

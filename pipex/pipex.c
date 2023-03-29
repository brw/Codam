#include <errno.h>
#include <fcntl.h>
#include <libft.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ft_printf.h>

void	cmd_not_found(char *cmd)
{
	ft_dprintf(STDERR_FILENO, "pipex: %s: command not found", cmd);
	exit(127);
}

char	*get_path_env(char **envp)
{
	while (*envp)
	{
		if (ft_strncmp(*envp, "PATH=", 5) == 0)
			return (*envp + 5);
		envp++;
	}
	return (NULL);
}

char	*get_cmd_path(char *cmd, char **paths)
{
	char	*try_path;

	if (cmd[0] == '/' && access(cmd, X_OK) == 0)
		return (cmd);
	while (*paths)
	{
		try_path = ft_strjoin(ft_strjoin(*paths, "/"), cmd);
		if (access(try_path, X_OK) == 0)
			return (try_path);
		free(try_path);
		paths++;
	}
	cmd_not_found(cmd);
	return (NULL);
}

void	run_cmd(int nbr, int pipefd[2], char *cmdstr, int file, char **paths,
		char **envp)
{
	char	**args;
	char	*cmd;
	pid_t	pid;

	pid = 0;
	if (nbr == 1)
		pid = fork();
	if (pid != 0)
		return ;
	args = ft_split_args(cmdstr); // TODO: remove single quotes around args
	cmd = get_cmd_path(args[0], paths);
	if (cmd == NULL || file == -1)
		exit(1);
	if (nbr == 1)
		dup2(file, STDIN_FILENO);
	else if (nbr == 2)
		dup2(file, STDOUT_FILENO);
	dup2(pipefd[nbr % 2], nbr % 2);
	close(file);
	close(pipefd[0]);
	close(pipefd[1]);
	if (execve(cmd, args, envp) == -1)
		perror("error");
	exit(errno);
}

int	main(int argc, char **argv, char **envp)
{
	char	**paths;
	int		infile;
	int		outfile;
	int		pipefd[2];

	if (argc != 5)
		exit(1);
	infile = open(argv[1], O_RDONLY);
	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	paths = ft_split(get_path_env(envp), ':');
	pipe(pipefd);
	run_cmd(1, pipefd, argv[2], infile, paths, envp);
	run_cmd(2, pipefd, argv[3], outfile, paths, envp);
	close(pipefd[0]);
	close(pipefd[1]);
	wait(NULL);
}

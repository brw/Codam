#include <fcntl.h>
#include <libft.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char	*find_path_env(char **envp)
{
	while (*envp)
	{
		if (ft_strncmp(*envp, "PATH", 4) == 0)
			return (*envp);
		envp++;
	}
	return (NULL);
}

char	*get_cmd_path(char *cmd, char **paths)
{
	char	*try_path;

	while (*paths)
	{
		try_path = ft_strjoin(ft_strjoin(*paths, "/"), cmd);
		if (access(try_path, X_OK) == 0)
			return (try_path);
		free(try_path);
		paths++;
	}
	return (NULL);
}

int	run_subprocess(int nbr, int pipefd[2], char *cmdstr, int file, char **paths,
		char **envp)
{
	char	**args;
	char	*cmd;
	pid_t	pid;

	args = ft_split(cmdstr, ' ');
	cmd = get_cmd_path(args[0], paths);
	pid = fork();
	if (pid == -1)
		return (-1);
	else if (pid > 0)
		return (pid);
	if (nbr == 1)
	{
		close(pipefd[0]);
		dup2(file, STDIN_FILENO);
		dup2(pipefd[1], STDOUT_FILENO);
		close(pipefd[1]);
	}
	else if (nbr == 2)
	{
		close(pipefd[1]);
		dup2(pipefd[0], STDIN_FILENO);
		dup2(file, STDOUT_FILENO);
		close(pipefd[1]);
	}
	return (execve(cmd, args, envp));
}

int	main(int argc, char **argv, char **envp)
{
	char	**paths;
	int		infile;
	int		outfile;
	int		pipefd[2];
	pid_t	pid1;
	pid_t	pid2;

	infile = open(argv[1], O_RDONLY);
	outfile = open(argv[4], O_WRONLY | O_CREAT, 0644);
	paths = ft_split(find_path_env(envp) + 5, ':');
	pipe(pipefd);
	pid1 = run_subprocess(1, pipefd, argv[2], infile, paths, envp);
	pid2 = run_subprocess(2, pipefd, argv[3], outfile, paths, envp);
	close(pipefd[0]);
	close(pipefd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}

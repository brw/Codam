#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <libft.h>

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

int	main(int argc, char **argv, char **envp)
{
	char	*infile;
	char	*cmd1;
	char	*cmd2;
	char	*outfile;
	char	**paths;

	infile = argv[1];
	paths = ft_split(find_path_env(envp) + 5, ':');
	cmd1 = get_cmd_path(argv[2], paths);
	char	*args[] = { "-l", NULL };
	cmd2 = argv[3];
	outfile = argv[4];

	execve(cmd1, args, envp);
}

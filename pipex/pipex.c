#include <pipex.h>

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

int	main(int argc, char **argv)
{
	t_context	ctx;
	pid_t		last_pid;
	int			status;

	handle_args(&ctx, argc, argv);
	ctx.paths = ft_split(get_path_env(environ), ':');
	while (ctx.cmd_i < argc - 1)
	{
		setup_redirs(&ctx, argc, argv);
		last_pid = spawn_child(&ctx, argv[ctx.cmd_i]);
		if (ctx.in.type == FD)
			close(ctx.in.fd);
		if (ctx.out.type == FD)
			close(ctx.out.fd);
		ctx.cmd_i++;
	}
	waitpid(last_pid, &status, 0);
	while (wait(NULL) != -1)
		continue ;
	if (ctx.heredoc == true)
		unlink("/tmp/pipex_heredoc_tmp");
	free_array(ctx.paths);
	exit(WEXITSTATUS(status));
}

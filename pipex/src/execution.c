/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   execution.c                                       :+:    :+:             */
/*                                                    +:+                     */
/*   By: bvan-den <bvan-den@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2023/06/01 21:55:16 by bvan-den      #+#    #+#                 */
/*   Updated: 2023/06/01 21:55:41 by bvan-den      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

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
			if (access(try_path, X_OK) == 0)
				return (free_array(ctx->paths), try_path);
			exit_error(ctx, try_path, NULL, 126);
		}
		free(try_path);
		i++;
	}
	exit_error(ctx, cmd, "command not found", 127);
	return (NULL);
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

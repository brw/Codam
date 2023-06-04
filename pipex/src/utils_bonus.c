/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   utils_bonus.c                                     :+:    :+:             */
/*                                                    +:+                     */
/*   By: bvan-den <bvan-den@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2023/06/01 21:55:41 by bvan-den      #+#    #+#                 */
/*   Updated: 2023/06/06 04:57:10 by bvan-den      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <pipex_bonus.h>

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

void	free_obj_exit_error(t_context *ctx, char *obj, char *msg, int exit_code)
{
	if (!msg)
		msg = strerror(errno);
	if (obj)
		ft_dprintf(STDERR_FILENO, "%s: %s: %s\n", ctx->program_name, obj, msg);
	else
		ft_dprintf(STDERR_FILENO, "%s: %s\n", ctx->program_name, msg);
	if (ctx->paths)
		free_array(ctx->paths);
	free(obj);
	exit(exit_code);
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

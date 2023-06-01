/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   handle_args.c                                     :+:    :+:             */
/*                                                    +:+                     */
/*   By: bvan-den <bvan-den@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2023/06/01 21:55:41 by bvan-den      #+#    #+#                 */
/*   Updated: 2023/06/01 21:55:41 by bvan-den      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

void	handle_args(t_context *ctx, int argc, char **argv)
{
	ctx->program_name = argv[0];
	ctx->paths = NULL;
	if (argc != 5)
		exit_error(ctx, NULL, "Needs exactly 4 arguments", 1);
	ctx->cmd_i = 2;
}

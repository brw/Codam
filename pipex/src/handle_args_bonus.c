/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   handle_args_bonus.c                               :+:    :+:             */
/*                                                    +:+                     */
/*   By: bvan-den <bvan-den@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2023/06/01 21:55:41 by bvan-den      #+#    #+#                 */
/*   Updated: 2023/06/01 21:55:41 by bvan-den      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <pipex_bonus.h>

#define HEREDOC_TMP_FILE "/tmp/pipex_heredoc_tmp"

void	handle_heredoc(t_context *ctx, int argc, char **argv)
{
	int		tmp_fd;
	char	*line;
	char	*delim;

	if (argc < 6)
		exit_error(ctx, NULL, "Needs >=2 commands and output file", 1);
	tmp_fd = open(HEREDOC_TMP_FILE, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (tmp_fd == -1)
		exit_error(ctx, HEREDOC_TMP_FILE, NULL, errno);
	delim = argv[2];
	while (true)
	{
		ft_printf("> ");
		line = get_next_line(STDIN_FILENO);
		if (!line || ft_strncmp(line, delim, ft_strlen(delim)) == 0)
		{
			free(line);
			break ;
		}
		ft_putstr_fd(line, tmp_fd);
		free(line);
	}
	close(tmp_fd);
	ctx->in.type = FILENAME;
	ctx->in.filename = HEREDOC_TMP_FILE;
}

void	handle_args(t_context *ctx, int argc, char **argv)
{
	ctx->program_name = argv[0];
	ctx->paths = NULL;
	ctx->heredoc = false;
	if (argc > 1 && ft_strncmp(argv[1], "here_doc", 9) == 0)
	{
		handle_heredoc(ctx, argc, argv);
		ctx->heredoc = true;
		ctx->cmd_i = 3;
	}
	else
	{
		if (argc < 5)
			exit_error(ctx, NULL, "Needs >=2 commands and output file", 1);
		ctx->cmd_i = 2;
	}
}

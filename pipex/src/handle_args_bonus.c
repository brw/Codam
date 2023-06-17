/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   handle_args_bonus.c                               :+:    :+:             */
/*                                                    +:+                     */
/*   By: bvan-den <bvan-den@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2023/06/01 21:55:41 by bvan-den      #+#    #+#                 */
/*   Updated: 2023/06/17 19:58:45 by bvan-den      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <pipex_bonus.h>

#define HEREDOC_TMP_FILE "/tmp/pipex_heredoc_tmp"

int	process_input(char *delim, size_t delim_len, int fd)
{
	char	*line;

	ft_printf("> ");
	line = get_next_line(STDIN_FILENO);
	if (!line || (ft_strncmp(line, delim, delim_len) == 0
			&& line[delim_len] == '\n'))
	{
		free(line);
		return (0);
	}
	ft_putstr_fd(line, fd);
	free(line);
	return (1);
}

void	handle_heredoc(t_context *ctx, char **argv)
{
	int		tmp_fd;
	char	*delim;
	size_t	delim_len;

	tmp_fd = open(HEREDOC_TMP_FILE, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (tmp_fd == -1)
		exit_error(ctx, HEREDOC_TMP_FILE, NULL, errno);
	delim = argv[2];
	delim_len = ft_strlen(delim);
	while (process_input(delim, delim_len, tmp_fd))
		continue ;
	close(tmp_fd);
	ctx->in.type = FILENAME;
	ctx->in.filename = HEREDOC_TMP_FILE;
}

void	handle_args(t_context *ctx, int argc, char **argv)
{
	ctx->program_name = argv[0];
	ctx->paths = NULL;
	ctx->heredoc = false;
	if (argc > 1 && ft_strcmp(argv[1], "here_doc") == 0)
	{
		if (argc < 6)
			exit_error(ctx, NULL, "Needs >=2 commands and output file", 1);
		handle_heredoc(ctx, argv);
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _heredoc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 12:48:09 by nduvoid           #+#    #+#             */
/*   Updated: 2025/06/03 16:29:56 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Header

/* -----| Internals |----- */
#include "_exec.h"
#include "_redirections.h"

/* -----| Modules   |----- */
#include "exec.h"

#pragma endregion Header
#pragma region Fonctions

/**
 * @brief Reads lines from standard input until the delimiter is encountered,
 *  and writes them to the specified file descriptor.
 * 
 * @param	delimiter	The string that marks the end of input.
 * @param	fd			The file descriptor to write the input to.
 * 
 * @return	Returns the number of lines read and written to the file descriptor.
 * 
 * @todo: we should write one time, not evry line.
 */
int	heredoc(
	const char *const restrict delimiter,
	int fd
)
{
	char			*line;
	int				pipe_fd[2];
	register int	i;

	if (pipe(pipe_fd) < 0)
		return (-1);
	else if (_piping(pipe_fd, &fd) < 0)
	{
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		return (-1);
	}
	line = read_line(DEFAULT_HEREDOC);
	while (line && ft_strncmp(line, delimiter, ft_strlen(delimiter)))
	{
		i = write(pipe_fd[1], line, ft_strlen(line));
		if (i < 0)
		{
			free(line);
			close(pipe_fd[0]);
			close(pipe_fd[1]);
			return (-1);
		}
		write(pipe_fd[1], "\n", 1);
		mm_free(line);
		line = read_line(DEFAULT_HEREDOC);
	}
	if (line)
		mm_free(line);
	fdm_close(pipe_fd[0]);
	fdm_close(pipe_fd[1]);
	return (0);
}

#pragma endregion Fonctions
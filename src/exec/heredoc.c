/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 12:48:09 by nduvoid           #+#    #+#             */
/*   Updated: 2025/09/17 10:48:09 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* -----| Internals |----- */
#include "_exec.h"
#include "_redirections.h"

/* -----| Modules   |----- */
#include "exec.h"
#include "env.h"

extern volatile sig_atomic_t	g_last_signal;

/**
 * @brief Reads lines from standard input until the sep is encountered,
 * and stores them in a dynamically allocated array.
 * 
 * @param	char	**storage           Pointer to a pointer that will hold
 * 					the address of the dynamically allocated array of strings.
 * @param	char	*restrict sep The string that marks the end of input.
 * 
 * @return	Returns all readed lines
 * * @retval	char **	All readed lines stored in a dynamically allocated array.
 * * @retval	NULL	If memory allocation fails or if an error occurs
 * 						during reading.
 * 
 * @version 1.0
*/
static inline char	**_read(
	char **storage,
	const char *const restrict sep
)
{
	const char		*prompt = env_find("PS2");
	char			*line;
	char			**new_storage;
	register int	i;

	line = read_line(prompt);
	i = 0;
	while (line && line[0] != '\04'
		&& ft_strncmp(line, sep, ft_strlen(sep) + 1))
	{
		if ((i + 1) % HD_ALLOC_SIZE == 0)
		{
			new_storage = mm_alloc((i + HD_ALLOC_SIZE + 1) * sizeof(char *));
			if (_UNLIKELY(!new_storage))
				return (mm_free(line), mm_free(storage), NULL);
			ft_memcpy(new_storage, storage, i * sizeof(char *));
			mm_free(storage);
			storage = new_storage;
		}
		(storage)[i++] = line;
		line = read_line(prompt);
	}
	if (_UNLIKELY(!line))
		return (free_tab(storage), NULL);
	return (mm_free(line), storage);
}

/**
 * @brief Writes the lines stored in the array to the specified file descriptor.
 * 
 * @param	char	**storage The array of strings to write.
 * @param	int		nb_lines  The number of lines in the array.
 * @param	int		fd		  The file descriptor to write to.
 * 
 * @return	Returns the exit code of the write operation.
 * * @retval	0	Success, all lines written.
 * * @retval	-1	Memory allocation failed.
 * * @retval	-2	Write operation failed.
 *
 * @version 1.0
*/
__attribute__((always_inline, used))
static inline int	_write(
	const char *const *const storage,
	const int fd
)
{
	register int	i;
	int				exit_code;
	char			*expanded;

	exit_code = 0;
	i = -1;
	while (storage[++i] && exit_code > -1)
	{
		expanded = env_expand((void *)storage[i]);
		if (_UNLIKELY(!expanded))
			return (ft_perror("%s", __func__), -1);
		exit_code = ft_fprintf(fd, "%s\n", expanded);
		mm_free(expanded);
	}
	return (exit_code > 0);
}

/**
 * @brief Reads lines from standard input until the sep is encountered,
 * 		and writes them to the specified file descriptor.
 * 
 * @param	char	*const sep string that marks the end.
 * @param	int		fd The file descriptor to write to.
 * 
 * @return	Returns the exit code of the heredoc operation.
 * * @retval	>= 0	The exit code of the write operation.
 * * @retval	-1	Memory allocation failed.
 * * @retval	-2	Error occurred during reading.
 * * @retval	-3	No lines read before the sep.
 * 
 * @version 3.0
 */
int	heredoc(
	const char *const restrict sep,
	int fd
)
{
	char	**storage;
	int		exit_code;

	storage = mm_alloc(sizeof(char *) * (HD_ALLOC_SIZE + 1));
	if (_UNLIKELY(!storage))
		return (-1);
	storage = _read(storage, sep);
	if (_UNLIKELY(!storage))
		return (mm_free(storage), -2);
	exit_code = _write((const char *const *const)storage, fd);
	if (_UNLIKELY(exit_code < 0))
		return (free_tab(storage), exit_code);
	else
		return (mm_free(storage), exit_code);
}

/**
 * @brief Creates a pipe and reads lines from standard input until the sep
 * is encountered, writing them to the write end of the pipe.
 *
 * @param	char	*const sep string that marks the end.
 *
 * @return	Returns the read end of the pipe.
 *  @retval	>= 0	The read end of the pipe.
 *  @retval	-1	Error occurred during pipe creation or heredoc operation.
 *
 * @version 1.0
 */
int	heredoc_all(
	const char *const restrict sep
)
{
	int	here_fd[2];
	int	out;

	if (pipe(here_fd) == -1)
		return (perror("heredoc_all(): pipe() failed"), -1);
	else
	{
		out = heredoc(sep, here_fd[1]);
		fdm_close(here_fd[1]);
	}
	if (_UNLIKELY(out < 0))
	{
		if (out == -2)
			g_last_signal = 130;
		return (fdm_close(here_fd[0]), out);
	}
	return (here_fd[0]);
}

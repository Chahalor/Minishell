/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc__.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 12:48:09 by nduvoid           #+#    #+#             */
/*   Updated: 2025/07/28 15:46:48 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Header

/* -----| Internals |----- */
#include "exec__.h"
#include "types__.h"

/* -----| Modules   |----- */
#include "../_public_/types.h"
#include "standards.h"

#pragma endregion Header
#pragma region Fonctions

static inline void	_free_tab(
	char **tab
)
{
	register int	i;

	if (unexpect(!tab))
		return ;
	i = -1;
	while (tab[++i])
		_manager()->mem.clean((unsigned char (1){mem_ptr}), none, tab[i], 0);
	_manager()->mem.clean((unsigned char (1){mem_ptr}), none, tab, 0);
}

/**
 * @brief Reads lines from standard input until the delimiter is encountered,
 * and stores them in a dynamically allocated array.
 * 
 * @param	char	**storage           Pointer to a pointer that will hold
 * 					the address of the dynamically allocated array of strings.
 * @param	char	*restrict delimiter The string that marks the end of input.
 * 
 * @return	Returns all readed lines
 * * @retval	char **	All readed lines stored in a dynamically allocated array.
 * * @retval	NULL	If memory allocation fails or if an error occurs
 * 						during reading.
 * 
 * @version 1.0
*/
static inline char	**_heredoc_read__(
	char **storage,
	const char *const restrict delimiter
)
{
	char						*line;
	char						**new_storage;
	register int				i;

	line = read_line(DEFAULT_HEREDOC);
	i = 0;
	while (line && ft_strncmp(line, delimiter, ft_strlen(delimiter) + 1))
	{
		if (unexpect((i + 1) % HD_ALLOC_SIZE == 0))
		{
			if (unexpect(_manager()->mem.alloc(mem_re, (void **)&new_storage,
				(i + HD_ALLOC_SIZE + 1) * sizeof(char *), mem_ptr) < 0))
					return (_manager()->mem.clean((unsigned char (1){mem_ptr}),
						none, line, 0), _free_tab(storage), NULL);
		}
		(storage)[i++] = line;
		(storage)[i] = NULL;
		line = read_line(DEFAULT_HEREDOC);
	}
	if (unexpect(!line))
		return (_free_tab(storage), NULL);
	_manager()->mem.clean((unsigned char (1){mem_ptr}), none, line, 0);
	return (storage);
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
 * @version 2.0
*/
__attribute__((always_inline, used))
static inline int	_heredoc_write__(
	const char *const *const storage,
	const int fd
)
{
	char			*expanded;
	register int	i;
	int				exit_code;

	exit_code = 0;
	i = -1;
	while (storage[++i] && exit_code > -1)
	{
		expanded = _manager()->env.expand(storage[i]);
		if (unexpect(!expanded))
			return (-1);
		exit_code = ft_fprintf(fd, "%s\n", expanded);
		_manager()->mem.clean((unsigned char (1){mem_free}), none, expanded, 0);
	}
	return (exit_code > 0);
}

/**
 * @brief Reads lines from standard input until the delimiter is encountered,
 * 		and writes them to the specified file descriptor.
 * 
 * @param	char	*const delimiter string that marks the end.
 * @param	int		fd The file descriptor to write to.
 * 
 * @return	Returns the exit code of the heredoc operation.
 * * @retval	>= 0	The exit code of the write operation.
 * * @retval	-1	Memory allocation failed.
 * * @retval	-2	Error occurred during reading.
 * * @retval	-3	No lines read before the delimiter.
 * 
 * @version 3.0
 */
static inline int	_heredoc_logic__(
	const char *const restrict delimiter,
	int fd
)
{
	char			**storage;
	int				exit_code;

	_manager()->mem.alloc(mem_new, (void **)&storage,
		sizeof(char *) * (HD_ALLOC_SIZE + 1), mem_ptr);
	if (unexpect(!storage))
		return (-1);
	storage = _heredoc_read__(storage, delimiter);
	if (unexpect(!storage))
		return (_manager()->mem.clean((unsigned char (1){mem_ptr}), none,
			storage, 0), -2);
	exit_code = _heredoc_write__((const char *const *const)storage, fd);
	if (unexpect(exit_code < 0))
		return (_free_tab(storage), exit_code);
	else
		return (_manager()->mem.clean((unsigned char (1){mem_ptr}), none,
			storage, 0), exit_code);
}

/**
 * @brief Creates a pipe and reads lines from standard input until the delimiter
 * is encountered, writing them to the write end of the pipe.
 *
 * @param	char	*const delimiter string that marks the end.
 *
 * @return	Returns the read end of the pipe.
 *  @retval	>= 0	The read end of the pipe.
 *  @retval	-1	Error occurred during pipe creation or heredoc operation.
 *
 * @version 1.0
 */
int	_heredoc__(
	const char *const restrict delimiter
)
{
	int	here_fd[2];
	int	out;

	if (pipe(here_fd) == -1)
		return (perror("heredoc_all(): pipe() failed"), -1);
	else
	{
		out = _heredoc_logic__(delimiter, here_fd[1]);
		close(here_fd[1]);
	}
	if (unexpect(out < 0))
		return (close(here_fd[0]), out);
	return (here_fd[0]);
}

#pragma endregion Fonctions
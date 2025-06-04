/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _heredoc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 12:48:09 by nduvoid           #+#    #+#             */
/*   Updated: 2025/06/04 09:49:13 by nduvoid          ###   ########.fr       */
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
 * and stores them in a dynamically allocated array.
 * 
 * @param	char	**storage           Pointer to a pointer that will hold
 * 					the address of the dynamically allocated array of strings.
 * @param	char	*restrict delimiter The string that marks the end of input.
 * 
 * @return	Returns the number of lines readed
 * * @retval	>= 0	The number of lines read and stored in the array.
 * * @retval	-1	An error occurred during memory allocation or reading.
 * 
 * @version 1.0
*/
static inline int	_read(
	char ***storage,
	const char *const restrict delimiter
)
{
	char			*line;
	char			**new_storage;
	register int	i;

	line = read_line(DEFAULT_HEREDOC);
	i = 0;
	while (line && ft_strncmp(line, delimiter, ft_strlen(delimiter) + 1))
	{
		if ((i + 1) % HEREDOC_ALLOC_SIZE == 0)
		{
			new_storage = mm_alloc((i + HEREDOC_ALLOC_SIZE + 1)
					* sizeof(char *));
			if (_UNLIKELY(!new_storage))
				return (mm_free(line), mm_free(*storage), -1);
			ft_memcpy(new_storage, *storage, i * sizeof(char *));
			mm_free(*storage);
			*storage = new_storage;
		}
		(*storage)[i++] = line;
		(*storage)[i] = NULL;
		line = read_line(DEFAULT_HEREDOC);
	}
	return (mm_free(line), i);
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
 * @note keep it to test the heredoc
 *
 * @version 1.0
*/
__attribute__((unused)) static inline int	_write(
	char *const *const storage,
	const int nb_lines,
	const int fd
)
{
	char			*final_line;
	size_t			len;
	register int	i;

	len = 0;
	i = -1;
	while (++i < nb_lines && storage[i])
		len += ft_strlen(storage[i]) + 1;
	final_line = mm_alloc(sizeof(char) * (len + 1));
	if (_UNLIKELY(!final_line))
		return (-1);
	i = -1;
	while (++i < nb_lines)
	{
		ft_memcpy(final_line + ft_strlen(final_line),
			storage[i], ft_strlen(storage[i]));
		final_line[ft_strlen(final_line)] = '\n';
		mm_free((void *)storage[i]);
	}
	final_line[len] = '\0';
	if (write(fd, final_line, len) == -1)
		return (mm_free(final_line), -2);
	else
		return (mm_free(final_line), 0);
}

/**
 * @brief Reads lines from standard input until the delimiter is encountered,
 *  and writes them to the specified file descriptor.
 * 
 * @param	char	*delimiter The string that marks the end of input.
 * @param	int		fd		   The file descriptor to write the input to.
 * 
 * @return	Returns all readed lines in a dynamically allocated array.
 * 
 * @todo: maybe we should return the char * and not an exit code (maybe)
 */
char	**heredoc(
	const char *const restrict delimiter,
	int fd
)
{
	char			**storage;
	register int	i;

	(void)fd;
	storage = mm_alloc(sizeof(char *) * (HEREDOC_ALLOC_SIZE + 1));
	if (_UNLIKELY(!storage))
		return (NULL);
	i = _read(&storage, delimiter);
	if (_UNLIKELY(i < 0))
		return (mm_free(storage), NULL);
	else if (!i)
		return (mm_free(storage), NULL);
	return (storage);
}

// _write(storage, i, fd);

#pragma endregion Fonctions
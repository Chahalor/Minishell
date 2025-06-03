/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _heredoc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 12:48:09 by nduvoid           #+#    #+#             */
/*   Updated: 2025/06/03 21:33:52 by nduvoid          ###   ########.fr       */
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

/** */
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
	while (line && ft_strncmp(line, delimiter, ft_strlen(delimiter)))
	{
		if ((i + 1) % HEREDOC_ALLOC_SIZE == 0)
		{
			new_storage = mm_alloc((i + HEREDOC_ALLOC_SIZE + 1) * sizeof(char *));
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

/** */
static inline int	_write(
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
 * @param	delimiter	The string that marks the end of input.
 * @param	fd			The file descriptor to write the input to.
 * 
 * @return	Returns the number of lines read and written to the file descriptor.
 * 
 * @todo: maybe we should return the char * and not an exit code (maybe)
 */
int	heredoc(
	const char *const restrict delimiter,
	int fd
)
{
	char			**storage;
	register int	i;

	storage = mm_alloc(sizeof(char *) * (HEREDOC_ALLOC_SIZE + 1));
	if (_UNLIKELY(!storage))
		return (-1);
	i = _read(&storage, delimiter);
	if (_UNLIKELY(i < 0))
		return (mm_free(storage), i);
	else if (!i)
		return (mm_free(storage), 0);
	_write(storage, i, fd);
	return (mm_free(storage), 0);
}

#pragma endregion Fonctions
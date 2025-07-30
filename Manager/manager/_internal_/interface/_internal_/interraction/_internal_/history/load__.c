/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load__.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 15:54:17 by nduvoid           #+#    #+#             */
/*   Updated: 2025/07/30 10:57:16 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Header

/* -----| Internals |----- */
#include "interraction__.h"
#include <fcntl.h>

/* -----| Modules  |----- */
#include "standards.h"

#pragma endregion Header
#pragma region Fonctions

/**
 * @brief	Count the number of lines in a file.
 * 
 * @param	filename The name of the file to count the lines in.
 * 
 * @return	The number of lines in the file.
 * @retval		>=0 if the file was opened successfully.
 * @retval		 -1 if the file could not be opened.
*/
__attribute__((always_inline, used))
static inline int	_count__(
	const char *const restrict filename
)
{
	const int	fd = open(filename, O_RDONLY, 0644);
	int			count;

	if (unexpect(fd < 0))
		return (ft_perror(ERROR
				"history load: opening %s file failed", filename), -1);
	count = count_lines(fd);
	close(fd);
	return (count);
}

/**
 * @brief	Skip the all lines if the file descriptor until only the 
 * 				_RL_HIST_SIZE lines are left.
 * 
 * @param	fd The file descriptor to read from.
 * @param	nb_lines The number of lines to skip.
 * 
 * @return	the number of lines skipped.
*/
__attribute__((always_inline, used))
static inline int	_skip__(
	const int fd,
	int nb_lines
)
{
	int	nb_skipped;

	if (expect(nb_lines <= _RL_HIST_SIZE))
		return (0);
	nb_skipped = 0;
	while (nb_lines-- > _RL_HIST_SIZE)
	{
		free(gnl(fd));
		++nb_skipped;
	}
	return (nb_skipped);
}

/**
 *  @brief	Create a history file if it does not exist.
 * 
 * @param	filename The name of the file to create.
 * 
 * @return	The file descriptor of the created file.
 * @retval		-1 if the file could not be created.
 * @retval		>= 0 if the file was created successfully.
*/
__attribute__((always_inline, used))
static inline int	_create__(
	const char *const restrict filename
)
{
	const int	fd = open(filename, O_RDWR | O_CREAT | O_APPEND, 0644);

	if (unexpect(fd < 0))
		return (perror(RED "Error:" RESET " creating history file failed"), -1);
	else
		return (fd);
}

/**
 * @brief	Load the history from a file.
 * 
 * @param	filename	The file to load
 * @param	data		The history data
 * 
 * @return	0 on success, -1 on error
 * @retval		 0 if the file is loaded successfully
 * @retval		-1 if the file descriptor is invalid
 * @retval		-2 if adding the history fails
 * 
 * @version 2.1
 */
__attribute__((cold, unused, always_inline))
inline int	_load_history__(
	const char *const restrict filename,
	t_rl_history *const restrict data
)
{
	const int		fd = open(filename, O_RDONLY, 0644);
	char			*line;
	register int	i;

	if (unexpect(fd < 0))
		return (data->fd = _create__(filename), 0);
	_skip__(fd, _count__(filename));
	_manager()->mem.reader.skip(fd, _RL_HIST_SIZE);
	line = _manager()->mem.reader.read(fd, NULL);	// @todo: check if this is correct
	i = -1;
	while (line && ++i < _RL_HIST_SIZE)
	{
		if (unexpect(!_history_manager(rl_add, line)))
		{
			close(fd);
			return (free(line), perror("Error: loading history failed"), -2);
		}
		free(line);
		line = _manager()->mem.reader.read(fd, NULL);
	}
	while (++i < _RL_HIST_SIZE)
		data->storage[i] = NULL;
	close(fd);
	data->fd = open(filename, O_RDWR | O_APPEND);
	return (0);
}

#pragma endregion Fonctions
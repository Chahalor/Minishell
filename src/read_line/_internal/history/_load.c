/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _load.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 15:54:17 by nduvoid           #+#    #+#             */
/*   Updated: 2025/05/28 16:46:05 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Header

/* -----| Internals |----- */
#include "_read_line.h"

/* -----| Modules   |----- */
#include "read_line.h"

#pragma endregion Header
#pragma region Fonctions

/** */
__attribute__((always_inline, used)) static inline int	_create(
	const char *const restrict filename
)
{
	const int	fd = open(filename, O_RDWR | O_CREAT | O_APPEND, 0644);

	if (_UNLIKELY(fd < 0))
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
 * @version 2.0
 */
__attribute__((cold, unused)) int	_load_history(
	const char *const restrict filename,
	t_rl_history *const restrict data
)
{
	const int		fd = open(filename, O_RDONLY, 0644);
	char			*line;
	register int	i;

	if (_UNLIKELY(fd < 0))
		return (data->fd = _create(filename), 0);
	line = gnl(fd);
	i = -1;
	while (line && ++i < _RL_HIST_SIZE)
	{
		if (__builtin_expect(!_history_manager(rl_add, line), unexpected))
		{
			close(fd);
			return (free(line), perror("Error: loading history failed"), -2);
		}
		free(line);
		line = gnl(fd);
	}
	while (++i < _RL_HIST_SIZE)
		data->storage[i] = NULL;
	close(fd);
	data->fd = open(filename, O_RDWR | O_APPEND);
	return (0);
}

#pragma endregion Fonctions
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _load.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 15:54:17 by nduvoid           #+#    #+#             */
/*   Updated: 2025/05/16 08:37:24 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Header

/* -----| Internals |----- */
#include "_read_line.h"
#include <fcntl.h>

/* -----| Modules   |----- */
#include "read_line.h"

#pragma endregion Header
#pragma region Fonctions

/** */
__attribute__((always_inline, used)) static inline int	_creat_file(
	const char *const restrict filename
)	// v.1 >> 
{
	const int	fd = open(filename, O_CREAT | O_WRONLY | O_APPEND, 0644);

	ft_printf("rl->history->_load_history(): open() %s\n", filename);	//rm
	if (__builtin_expect(fd < 0, unexpected))
	{
		perror("rl->history->_load_history(): open() failed");
		return (-1);
	}
	return (fd);
}

/** */
__attribute__((cold, unused)) int	_load_history(
	const char *const restrict filename,
	t_rl_history *const restrict data
)	// v.1 >> fonction struct will change
{
	const int		fd = open(filename, O_RDONLY, 0644);
	t_rl_history	*history;
	char			*line;

	history = mm_alloc(sizeof(t_rl_history));
	if (__builtin_expect(!history, unexpected))
	{
		perror("Error: mm_alloc() failed");
		close(fd);
		return (-1);
	}
	line = gnl(fd);
	while (line)
	{
		if (__builtin_expect(!rl_add_history(line), unexpected))
		{
			perror("Error: rl_add_history() failed");
			free(line);
			close(fd);
			return (-1);
		}
		free(line);
		line = gnl(fd);
	}
	data->fd = _creat_file(filename);
	close(fd);
	return (0);
}

#pragma endregion Fonctions
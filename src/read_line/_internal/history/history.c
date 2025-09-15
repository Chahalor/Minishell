/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 08:08:28 by nduvoid           #+#    #+#             */
/*   Updated: 2025/09/15 19:24:55 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Header

/* -----| Internals |----- */
#include "_read_line.h"

/* -----| Modules   |----- */
#include "read_line.h"

#pragma endregion Header
#pragma region Fonctions

extern char	*_history_get(
				t_rl_history *const restrict data,
				const int access
				);

/** */
__attribute__((always_inline, used)) static inline char	*_history_get_all(
	t_rl_history *const restrict data
)
{
	static t_history	result = (t_history){
		.storage = {0},
		.pos = 0
	};

	ft_memcpy(result.storage, data->storage, sizeof(char *) * _RL_HIST_SIZE);
	result.pos = data->pos;
	return ((char *)&result);
}

/**
 * @brief	Add a line to the history by duplicating it.
 * 
 * @param	line	The line to add
 * @param	data	The history data
 * 
 * @return	The line added to the history
 * @retval		NULL if the history is NULL
 * @retval		The line added to the history
 * 
 * @version 2.0
*/
__attribute__((always_inline, used)) static inline char	*_history_add(
	const char *const restrict line,
	t_rl_history *const restrict data
)
{
	const int	len = ft_strlen(line);
	char		*str;

	if (_UNLIKELY(!data || !line || !*line || line[0] == '\n' || len < 1))
		return (NULL);
	else
	{
		str = (char *)mm_alloc(len + 1);
		if (_UNLIKELY(!str))
			return (NULL);
		ft_memcpy(str, line, len);
		str[len] = '\0';
		data->storage[data->pos] = str;
		data->pos = (data->pos + 1) % _RL_HIST_SIZE;
		data->size += (data->size < _RL_HIST_SIZE);
		if (_LIKELY(data->fd > 0))
			ft_fprintf(data->fd, "%s\n", str);
		return (str);
	}
}

/**
 * @brief	Clear the history by freeing all the lines.
 * 
 * @param	data	The history data
 * 
 * @return	NULL always
 * 
 * @version 2.0
 */
__attribute__((always_inline, used)) static inline char	*_clear(
	t_rl_history *const restrict data
)
{
	if (_UNLIKELY(!data))
		return (NULL);
	else
	{
		while (--data->size >= 0)
		{
			mm_free(data->storage[data->size]);
			data->storage[data->size] = NULL;
		}
	}
	data->size = 0;
	data->pos = 0;
	if (data->fd)
	{
		close(data->fd);
		data->fd = -1;
	}
	return (NULL);
}

/**
 * @brief	Manage the history by adding, clearing or getting the next/previous
 *  line.
 * 
 * @param	access	The access type
 * @param	line	The line to add
 * 
 * @return	The line added to the history
 * @retval		NULL if an error occurs or when clearing the history
 * @retval		The line added to the history or the next/previous line
 * 
 * @version 2.0
*/
__attribute__((used)) char	*_history_manager(
	const int access,
	const char *const restrict line
)
{
	static t_rl_history	history = {0};

	if (_LIKELY(access == rl_get_next || access == rl_get_prev))
		return (_history_get(&history, access));
	else if (_LIKELY(access == rl_add))
		return (_history_add(line, &history));
	else if (access == rl_reset_pos)
		history.pos = history.size;
	else if (access == rl_get_all)
		return (_history_get_all(&history));
	else if (_UNLIKELY(access == rl_load))
	{
		_neutral(history.storage, sizeof(char *) * (_RL_HIST_SIZE + 1));
		_load_history(line, &history);
		return (NULL);
	}
	else if (_UNLIKELY(access == rl_clear))
		return (_clear(&history));
	return (NULL);
}

#pragma endregion Fonctions
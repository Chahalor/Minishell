/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 08:08:28 by nduvoid           #+#    #+#             */
/*   Updated: 2025/05/22 14:38:01 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Header

/* -----| Internals |----- */
#include "_read_line.h"

/* -----| Modules   |----- */
#include "read_line.h"

#pragma endregion Header
#pragma region Fonctions

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

	if (_UNLIKELY(!data))
		return (NULL);
	else
	{
		data->storage[data->pos] = memdup(line, len + 1);
		data->pos = (data->pos + 1) % _RL_HIST_SIZE;
		data->size += (data->size < _RL_HIST_SIZE);
		if (_LIKELY(data->fd > 0))
			ft_fprintf(data->fd, "%s\n", line);
		return (data->storage[data->pos]);
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
		while (--data->size > 0)
		{
			mm_free(data->storage[data->size]);
			data->storage[data->size] = NULL;
		}
	}
	data->pos = 0;
	return (NULL);
}

/**
 * @brief	Manage the history by adding, clearing or getting the next/previous line.
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
	char				*result;

	if (_LIKELY(access == rl_get_next))
	{
		result = history.storage[history.pos];
		if (result)
			history.pos = (history.pos + 1) % _RL_HIST_SIZE;
		// ft_printf("result: %s (%d)\n", result, history.pos);	//rm
		return (result);
	}
	else if (_LIKELY(access == rl_get_prev))
	{
		history.pos = (history.pos - 1 + _RL_HIST_SIZE) % _RL_HIST_SIZE;
		result = history.storage[history.pos];
		if (!result)
			history.pos = (history.pos + 1) % _RL_HIST_SIZE;
		// ft_printf("result: %s (%d)\n", result, history.pos);	//rm
		return (result);
	}
	else if (_LIKELY(access == rl_add))
		return (_history_add(line, &history));
	else if (access == rl_reset_pos)
		history.pos = history.size;
	else if (access == rl_get_all)
		return (NULL);
	else if (_UNLIKELY(access == rl_load))
	{
		if (_UNLIKELY(_load_history(line, &history) < 0))
			return (NULL);
		else
			return (history.storage[history.pos]);
	}
	else if (_UNLIKELY(access == rl_clear))
		return (_clear(&history));
	return (NULL);
}

#pragma endregion Fonctions
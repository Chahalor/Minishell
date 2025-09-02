/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _get.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 08:08:28 by nduvoid           #+#    #+#             */
/*   Updated: 2025/09/02 08:55:25 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Header

/* -----| Internals |----- */
#include "_read_line.h"

/* -----| Modules   |----- */
#include "read_line.h"

#pragma endregion Header
#pragma region Fonctions

static inline char	*__rl_hist_get_next(
	t_rl_history *const restrict data
)
{
	int		start;
	char	*result;
	char	*last;

	last = data->storage[data->pos];
	start = data->pos;
	data->pos = (data->pos + 1) % _RL_HIST_SIZE;
	result = data->storage[data->pos];
	if (data->pos == start || !result)
	{
		data->pos = start;
		return (NULL);
	}
	while (result && last && ft_strncmp(result, last, ft_strlen(last)) == 0)
	{
		data->pos = (data->pos + 1) % _RL_HIST_SIZE;
		result = data->storage[data->pos];
		if (data->pos == start)
			return (NULL);
	}
	return (result);
}

static inline char	*__rl_hist_get_prev(
	t_rl_history *const restrict data
)
{
	int		start;
	char	*result;
	char	*last;

	last = data->storage[data->pos];
	start = data->pos;
	data->pos = (data->pos - 1 + _RL_HIST_SIZE) % _RL_HIST_SIZE;
	result = data->storage[data->pos];
	if (data->pos == start || !result)
	{
		data->pos = start;
		return (NULL);
	}
	while (result && last && ft_strncmp(result, last, ft_strlen(last)) == 0)
	{
		data->pos = (data->pos - 1 + _RL_HIST_SIZE) % _RL_HIST_SIZE;
		result = data->storage[data->pos];
		if (data->pos == start)
			return (NULL);
	}
	return (result);
}

/**
 * @brief	return the next/previous line in the history.
 * 
 * @param	data		The history data
 * @param	direction	The direction to go
 * 
 * @return	The line in the history
 * @retval		NULL if there is no line in this direction
 * @retval		The line in the history
 * 
 * @version 1.0
*/
__attribute__((always_inline, used))
extern inline char	*_history_get(
	t_rl_history *const restrict data,
	const int access
)
{
	if (_UNLIKELY(!data))
		return (NULL);
	else if (_LIKELY(access == rl_get_next))
		return (__rl_hist_get_next(data));
	else if (_LIKELY(access == rl_get_prev))
		return (__rl_hist_get_prev(data));
	return (NULL);
}

#pragma endregion Fonctions
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _get.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 08:08:28 by nduvoid           #+#    #+#             */
/*   Updated: 2025/09/15 14:57:03 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Header

/* -----| Internals |----- */
#include "_read_line.h"

/* -----| Modules   |----- */
#include "read_line.h"

#pragma endregion Header
#pragma region Fonctions

static inline int	__cmp(
	const char *const restrict str1,
	const char *const restrict str2
)
{
	register int	__i;

	if (_UNLIKELY(!str1 || !str2))
		return (0);
	__i = 0;
	while (str1[__i] && str2[__i] && str1[__i] == str2[__i])
		__i++;
	return ((unsigned char)str1[__i] - (unsigned char)str2[__i]);
}

static inline char	*__rl_hist_get_next(
	t_rl_history *const restrict data
)
{
	char	*_result;
	char	*__last;
	int		__start;
	int		__pos;

	__last = data->storage[data->pos];
	__start = data->pos;
	__pos = (data->pos + 1) % _RL_HIST_SIZE;
	_result = data->storage[__pos];
	if (__cmp(_result, __last) != 0)
	{
		data->pos = __pos;
		return (_result);
	}
	while (_result && __last && __cmp(_result, __last) == 0)
	{
		__pos = (__pos + 1) % _RL_HIST_SIZE;
		_result = data->storage[__pos];
		if (__pos == __start)
			break ;
	}
	if (_LIKELY(_result != NULL))
		data->pos = __pos;
	return (_result);
}

static inline char	*__rl_hist_get_prev(
	t_rl_history *const restrict data
)
{
	char	*_result;
	char	*__last;
	int		__start;
	int		__pos;

	__last = data->storage[data->pos];
	__start = data->pos;
	__pos = (data->pos - 1 + _RL_HIST_SIZE) % _RL_HIST_SIZE;
	_result = data->storage[__pos];
	if (__cmp(_result, __last) != 0)
	{
		data->pos = __pos;
		return (_result);
	}
	while (_result && __last && __cmp(_result, __last) == 0)
	{
		__pos = (__pos - 1 + _RL_HIST_SIZE) % _RL_HIST_SIZE;
		_result = data->storage[__pos];
		if (__pos == __start)
			break ;
	}
	if (_LIKELY(_result != NULL))
		data->pos = __pos;
	return (_result);
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
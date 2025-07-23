/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history__.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 08:08:28 by nduvoid           #+#    #+#             */
/*   Updated: 2025/07/23 18:17:59 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Header

/* -----| Internals |----- */
#include "../interraction__.h"

/* -----| Modules  |----- */
	//...

#pragma endregion Header
#pragma region Fonctions

/** */
__attribute__((always_inline, used))
static inline char	*_history_get_all__(
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
__attribute__((always_inline, used)) static inline char	*_history_add__(
	const char *const restrict line,
	t_rl_history *const restrict data
)
{
	const int	len = ft_strlen(line);
	const int	alloc_size = ((len + _RL_ALLOC_SIZE - 1) / _RL_ALLOC_SIZE)
		* _RL_ALLOC_SIZE + 1;

	if (_UNLIKELY(!data || !line || len < 1))
		return (NULL);
	else
	{
		data->storage[data->pos] = (char *)mm_alloc(alloc_size + 1);
		if (_UNLIKELY(!data->storage[data->pos]))
			return (NULL);
		ft_memcpy(data->storage[data->pos], line, len);
		data->storage[data->pos][len] = '\0';
		data->pos = (data->pos + 1) % _RL_HIST_SIZE;
		data->size += (data->size < _RL_HIST_SIZE);
		if (_LIKELY(data->fd > 0))
			ft_fprintf(data->fd, "%s\n", line);
		return ((char *)line);
	}
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
__attribute__((always_inline, used)) static inline char	*_history_get__(
	t_rl_history *const restrict data,
	const int access
)
{
	char	*result;

	if (_UNLIKELY(!data))
		return (NULL);
	else if (_LIKELY(access == rl_get_next))
	{
		data->pos = (data->pos + 1) % _RL_HIST_SIZE;
		result = data->storage[data->pos];
		if (!result)
			data->pos = (data->pos - 1 + _RL_HIST_SIZE) % _RL_HIST_SIZE;
		return (result);
	}
	else if (_LIKELY(access == rl_get_prev))
	{
		data->pos = (data->pos - 1 + _RL_HIST_SIZE) % _RL_HIST_SIZE;
		result = data->storage[data->pos];
		if (!result)
		{
			data->pos = (data->pos + 1) % _RL_HIST_SIZE;
			return (data->storage[data->pos]);
		}
		else
			return (result);
	}
	return (NULL);
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
__attribute__((always_inline, used)) static inline char	*_history_clear__(
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
	data->pos = 0;
	close(data->fd);
	data->fd = -1;
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
__attribute__((used, always_inline))
inline void	*_history_manager__(
	const int access,
	const char *const restrict line
)
{
	static t_rl_history	history = {0};

	if (_LIKELY(access == rl_get_next || access == rl_get_prev))
		return (_history_get__(&history, access));
	else if (_LIKELY(access == rl_add))
		return (_history_add__(line, &history));
	else if (access == rl_reset_pos)
		history.pos = history.size;
	else if (access == rl_get_all)
		return (_history_get_all__(&history));
	else if (_UNLIKELY(access == rl_load))
	{
		_load_history(line, &history);
		return (NULL);
	}
	else if (_UNLIKELY(access == rl_clear))
		return (_history_clear__(&history));
	return (NULL);
}

#pragma endregion Fonctions
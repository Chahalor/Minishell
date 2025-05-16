/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 08:08:28 by nduvoid           #+#    #+#             */
/*   Updated: 2025/05/16 09:25:33 by nduvoid          ###   ########.fr       */
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
__attribute__((always_inline, used)) static inline char	*history_add(
	const char *const restrict line,
	t_rl_history *const restrict data
)
{
	t_rl_history	*new_entry;
	int				len;

	if (!line || !*line)
		return (NULL);
	len = ft_strlen(line);
	new_entry = mm_alloc(sizeof(t_rl_history) + sizeof(char) * (_RL_ALLOC_SIZE + 1));
	if (__builtin_expect(!new_entry, unexpected))
		return (NULL);
	new_entry->line = (char *)(new_entry + 1);
	ft_memcpy(new_entry->line, line, len + 1);
	new_entry->next = NULL;
	new_entry->prev = data->tail;
	new_entry->head = data->head ? data->head : new_entry;
	if (data->tail)
		data->tail->next = new_entry;
	else
		data->head = new_entry;
	data->tail = new_entry;
	data->current = new_entry;
	if (data->fd >= 0)
	{
		write(data->fd, line, len);
		write(data->fd, "\n", 1);
	}
	return new_entry->line;
}


/** */
__attribute__((always_inline, used)) inline char	*_remove_history(
	t_rl_history *const restrict data
)
{
	t_rl_history	*tmp;

	if (__builtin_expect(!data, unexpected))
		return (NULL);
	if (data->tail == data->head)
		return (NULL);
	tmp = data->tail;
	data->tail = data->tail->prev;
	data->tail->next = NULL;
	mm_free(tmp);
	return (data->tail->line);
}

/** */
__attribute__((always_inline, used)) static inline char	*_clear(
	t_rl_history *const restrict data
)
{
	t_rl_history	*actual;
	t_rl_history	*tmp;

	if (__builtin_expect(!data, unexpected))
		return (NULL);
	actual = data->next;
	while (actual)
	{
		tmp = actual->next;
		mm_free(actual);
		actual = tmp;
	}
	mm_free(data);
	return (NULL);
}

/** */
__attribute__((always_inline, used)) static inline char	*_get(
	t_rl_history *const restrict data,
	const t_rl_hist_access access
)
{
	t_rl_history	*result;

	result = data->current;
	if (access == rl_get_prev)
	{
		if (data->current->prev)
		{
			result = data->current->prev;
			data->current = result;
		}
		else
			result = data->current;
	}
	else if (access == rl_get_next)
	{
		if (data->current->next)
		{
			result = data->current->next;
			data->current = result;
		}
		else
			result = data->current;
	}
	return (result->line);
}

/** */
__attribute__((used)) char	*_history_manager(
	const int access,
	const char *const restrict line
)
{
	static t_rl_history	*history = NULL;

	if (access == rl_get_prev || access == rl_get_next)
		return (_get(history, access));
	else if (access == rl_add)
		return (history_add(line, history));
	else if (access == rl_remove)
		return (_remove_history(history));
	else if (__builtin_expect(access == rl_clear, unexpected))
		return (_clear(history));
	else if (__builtin_expect(access == rl_init, unexpected))
	{
		history = mm_alloc(sizeof(t_rl_history));
		if (!history)
			return (NULL);
		*history = (t_rl_history){
			.line = NULL, .next = NULL, .prev = NULL,
			.head = history, .tail = history, .current = history,
			.fd = -1,
		};
		_load_history(line, history);
		return ((char *)history);
	}
	else
		return (NULL);
}

#pragma endregion Fonctions
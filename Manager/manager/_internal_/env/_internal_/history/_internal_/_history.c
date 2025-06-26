/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _history.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/05/23 10:59:17 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _HISTORY_C
# define _HISTORY_C

/* -------- modules --------- */
	// ---- access ----- //
# include "_history.h"

/* -------- inlines --------- */

// doc ...
__attribute__((always_inline, used))
//	(-hidden-)
extern inline char	_load_history(\
	t_histo_ *restrict const history
)	// v.1. >>> tag: def->load_history
{
	register unsigned int	i;

	if (unexpect(open(history->path, &history->fd) != no_error))
		return (failed_to_open);
	i = 0;
	while (i++ != HISTORY_SIZE)
		if (unexpect(\
				read(history->fd, \
					&history->content[HISTORY_SIZE - history->size++]) \
						!= no_error))
			return (failed_to_read);
	while (read(history->fd, NULL) == no_error)
		history->size++;
	return (no_error);
}

// doc ...
__attribute__((always_inline, used))
//	(-hidden-)
extern inline void	_unload_history(\
	t_histo_ *restrict const history
)	// v.1. >>> tag: def->unload_history
{
	register unsigned int	i;

	i = 0;
	while (i != HISTORY_SIZE)
		free(history->content[i++]);
	history->size = 0;
}

// doc ...
__attribute__((always_inline, used))
//	(-hidden-)
extern inline char	_show_history(\
	t_histo_ *restrict const history
)	// v.1. >>> tag: def->show_history
{
	// ...
	return (no_error);
}

// doc ...
__attribute__((always_inline, used))
//	(-hidden-)
extern inline char	_add_entry(\
	t_histo_ *restrict const history,
	const char *restrict const command
)	// v.1. >>> tag: def->add_entry
{
	if (unexpect(\
			write(history->fd, command, getlen(command, '\0')) != no_error))
		return (failed_to_write);
	history->content[history->head] = (char *)command;
	history->head = (history->head + 1) % HISTORY_SIZE;
	if (history->size == HISTORY_SIZE)
		history->tail = (history->tail + 1) % HISTORY_SIZE;
	else
		history->size++;
	return (no_error);
}

// doc ...
__attribute__((always_inline, used))
//	(-hidden-)
extern inline char *_get_entry(\
	t_histo_ *restrict const history,
	const unsigned int index
)	// v.1. >>> tag: def->get_entry
{
	if (unexpect(index > HISTORY_SIZE))
		return (invalid_value_error);
	return (history->content[(history->tail + index) % HISTORY_SIZE]);
}

#endif
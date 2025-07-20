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

#ifndef ADD___C
# define ADD___C

/* -------- modules --------- */
	// ---- access ----- //
# include "history__.h"

/* -------- inlines --------- */

// doc ...
__attribute__((always_inline, used))
//	(-internal-)
extern inline char	__histo_add(\
	t_histo__ *restrict const histo__,
	t_mem *restrict const mem__,
	const char *restrict const cmd__
)	// v.1. >>> tag: def->_histo_add
{
	int	fd__;

	if (unexpect(\
			mem__->reader.find((unsigned char [1]){reader_file}, \
								HISTORY_FILE, (void **)&fd__) \
			!= no_error))
		return (error);
	if (unexpect(mem__->writer.write(fd__, cmd__) != no_error))
		return (error);
	histo__->content__[histo__->head__] = (char *)command;
	histo__->head__ = (histo__->head__ + 1) % HISTORY_SIZE;
	if (histo__->size__ == HISTORY_SIZE)
		histo__->tail__ = (histo__->tail__ + 1) % HISTORY_SIZE;
	else
		++histo__->size__;
	return (no_error);
}

#endif
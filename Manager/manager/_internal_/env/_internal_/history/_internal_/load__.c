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

#ifndef LOAD___C
# define LOAD___C

/* -------- modules --------- */
	// ---- access ----- //
# include "history__.h"

/* -------- inlines --------- */

// doc ...
__attribute__((always_inline, used))
//	(-internal-)
extern inline char	__histo_load(\
	t_histo__ *restrict const histo__,
	t_mem *restrict const mem__
)	// v.1. >>> tag: def->_histo_load
{
	int						fd__;
	char					*buffer__;
	register char			code__;

	if (unexpect(\
			mem__->reader.find((unsigned char [1]){reader_file}, \
								HISTORY_FILE, (void **)&fd__) \
			!= no_error))
		return (error);
	while (!code__)
	{
		code__ = mem__->reader.read(fd__, &buffer__);
		if (unexpect(_histo_add(buffer__) != no_error))
			return (error);
	}
	return (no_error);
}

#endif
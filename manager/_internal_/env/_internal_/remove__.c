/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _env.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/05/26 12:53:13 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REMOVE___C
# define REMOVE___C

/* -------- modules --------- */
	// ---- access ----- //
# include "env__.h"

/* -------- inlines --------- */

// doc ...
__attribute__((always_inline, used))
//	(-internal-)
extern inline char __env_unset(\
	t_env_ *restrict const env__,
	t_mem *restrict const mem__,
	const char *restrict const target__
)	// v.1. >>> tag: def->_env_set
{
	char			*buffer__;
	unsigned int	size__;

	buffer__ = _env_find(target__);
	if (buffer__)
	{
		size__ = mem__->size((unsigned char [1]){mem_len}, (void *)buffer__, 0);
		mem__->clean((unsigned char [1]){mem_ptr}, none, buffer__, size__);
	}
	return (no_error);
}

#endif
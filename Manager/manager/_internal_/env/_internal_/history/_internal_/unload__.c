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

#ifndef UNLOAD___C
# define UNLOAD___C

/* -------- modules --------- */
	// ---- access ----- //
# include "history__.h"

/* -------- inlines --------- */

// doc ...
__attribute__((always_inline, used))
//	(-internal-)
extern inline char	__histo_unload(\
	t_histo__ *restrict const histo__,
	t_mem *restrict const mem__
)	// v.1. >>> tag: def->_histo_unload
{
	char					*ptr__;
	register unsigned int	size__;
	register unsigned int	i__;

	i__ = 0;
	while (i__ != HISTORY_SIZE)
	{
		ptr__ = histo__->content__[i__++];
		size__ = mem__->size((unsigned char [1]){mem_len}, ptr__, 0);
		mem__->clean((unsigned char [1]){mem_ptr}, none, ptr__, size__);
	}
	return (no_error);
}

#endif
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

#ifndef FIND___C
# define FIND___C

/* -------- modules --------- */
	// ---- access ----- //
# include "history__.h"

/* -------- inlines --------- */

// doc ...
__attribute__((always_inline, used))
//	(-internal-)
extern inline char	__histo_find(\
	t_histo__ *restrict const histo__,
	const unsigned int index__
)	// v.1. >>> tag: def->_histo_find
{
	if (unexpect(index__ > HISTORY_SIZE))
		return (invalid_index_error_);
	return (histo__->content__[(histo__->tail__ + index__) % HISTORY_SIZE]);
}

#endif
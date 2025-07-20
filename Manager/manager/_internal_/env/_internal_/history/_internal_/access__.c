/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access__.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/06/27 10:37:24 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACCESS___C
# define ACCESS___C

/* -------- modules --------- */
	// ---- access ----- //
# include "history__.h"

/* -------- inlines --------- */

// doc ...
__attribute__((always_inline, used))
// (-internal-)
extern inline t_history_	*__history_get(\
	t_history_	*restrict const new__
)	// v.1. >>> tag: def->_history_get
{
	static t_history_	*restrict	history__ = NULL;

	if (unexpect(!history__ && new__))
		history__ = new__;
	return (history__);
}

// doc ...
__attribute__((always_inline, used))
// (-internal-)
extern inline t_history_	*__history_self(void)
	// v.1. >>> tag: def->_history_self
{
	return (_history_get(NULL));
}

#endif
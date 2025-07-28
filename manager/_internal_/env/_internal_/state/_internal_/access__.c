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
# include "state__.h"

/* -------- inlines --------- */

// doc ...
__attribute__((always_inline, used))
// (-internal-)
extern inline t_state_	*__state_get(\
	t_state_	*restrict const new__
)	// v.1. >>> tag: def->_state_get
{
	static t_state_	*restrict	state__ = NULL;

	if (unexpect(!state__ && new__))
		state__ = new__;
	return (state__);
}

// doc ...
__attribute__((always_inline, used))
// (-internal-)
extern inline t_state_	*__state_self(void)	// v.1. >>> tag: def->_state_self
{
	return (_state_get(NULL));
}

#endif
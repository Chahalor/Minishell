/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access__.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/06/20 13:46:54 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACCESS___C
# define ACCESS___C

/* -------- modules --------- */
	// ---- access ----- //
# include "interface__.h"

/* -------- inlines --------- */

// doc ...
__attribute__((always_inline, used))
// (-internal-)
extern inline t_interface_	*__interface_get(\
	t_interface_	*restrict const new__
)	// v.1. >>> tag: def->_interface_get
{
	static t_interface_	*restrict	interface__ = NULL;

	if (unexpect(!interface__ && new__))
		interface__ = new__;
	return (interface__);
}

// doc ...
__attribute__((always_inline, used))
// (-internal-)
extern inline t_interface_	*__interface_self(void)
// v.1. >>> tag: def->_interface_self
{
	return (_interface_get(NULL));
}

#endif
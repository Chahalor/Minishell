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
# include "visual__.h"

/* -------- inlines --------- */

// doc ...
__attribute__((always_inline, used))
// (-internal-)
extern inline t_visual_	*__visual_get(\
	t_visual_	*restrict const new__
)	// v.1. >>> tag: def->_visual_get
{
	static t_visual_	*restrict	visual__ = NULL;

	if (unexpect(!visual__ && new__))
		visual__ = new__;
	return (visual__);
}

// doc ...
__attribute__((always_inline, used))
// (-internal-)
extern inline t_visual_	*__visual_self(void)
// v.1. >>> tag: def->_visual_self
{
	return (_visual_get(NULL));
}

#endif
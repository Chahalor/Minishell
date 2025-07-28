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
# include "reader__.h"

/* -------- inlines --------- */

// doc ...
__attribute__((always_inline, used))
// (-internal-)
extern inline t_reader_	*__reader_get(\
	t_reader_	*restrict const new__
)	// v.1. >>> tag: def->_reader_get
{
	static t_reader_	*restrict	reader__ = NULL;

	if (unexpect(!reader__ && new__))
		reader__ = new__;
	return (reader__);
}

// doc ...
__attribute__((always_inline, used))
// (-internal-)
extern inline t_reader_	*__reader_self(void)	// v.1. >>> tag: def->_reader_self
{
	return (_reader_get(NULL));
}

#endif
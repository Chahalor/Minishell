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
# include "parse__.h"

/* -------- inlines --------- */

// doc ...
__attribute__((always_inline, used))
// (-internal-)
extern inline t_parse_	*__parse_get(\
	t_parse_	*restrict const new__
)	// v.1. >>> tag: def->_parse_get
{
	static t_parse_	*restrict	parse__ = NULL;

	if (unexpect(!parse__ && new__))
		parse__ = new__;
	return (parse__);
}

// doc ...
__attribute__((always_inline, used))
// (-internal-)
extern inline t_parse_	*__parse_self(void)	// v.1. >>> tag: def->_parse_self
{
	return (_parse_get(NULL));
}

#endif
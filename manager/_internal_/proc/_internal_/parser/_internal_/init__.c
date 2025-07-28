/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init__.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/06/25 15:06:11 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT___C
# define INIT___C

/* -------- modules --------- */
	// ---- access ----- //
# include "parser__.h"

/* -------- inlines --------- */

// doc ...
__attribute__((always_inline, used))
// (-internal-)
extern inline char	__parse_init(\
	t_parse_ *restrict const parse__
)	// v.1. >>> tag: def->parse_init
{
	*parse__ = (t_parse_){
		.parse_ = _parse \
	}
	if (unexpect(!_parse_get(parse__)))
		return (failed_to_setup);
	return (no_error \
			| token_init(&parse__->token) \
			| tree_init(parse__->tree__));
}

#endif
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
# include "tokenizer__.h"

/* -------- inlines --------- */

// doc ...
__attribute__((always_inline, used))
// (-internal-)
extern inline t_token_	*__token_get(\
	t_token_	*restrict const new__
)	// v.1. >>> tag: def->_token_get
{
	static t_token_	*restrict	token__ = NULL;

	if (unexpect(!token__ && new__))
		token__ = new__;
	return (token__);
}

// doc ...
__attribute__((always_inline, used))
// (-internal-)
extern inline t_token_	*__token_self(void)	// v.1. >>> tag: def->_token_self
{
	return (_token_get(NULL));
}

#endif
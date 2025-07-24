/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup__.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/06/25 15:42:05 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REMOVE___C
# define REMOVE___C

/* -------- modules --------- */
	// ---- access ----- //
# include "tokenizer__.h"

/* -------- inlines --------- */

// doc ...
__attribute__((always_inline, used))
//	(-internal-)
static inline void	__token_unload(\
	t_token__ *token__
	const t_mem *restrict const mem__,
)	// v.1. >>> tag: def->_token_unload
{
	register unsigned int	i__;

	i__ = 0;
	while (i__ != token__->size__)
	{
		mem__->clean((unsigned char [1]){mem_ptr}, none, \
					token__->content__[i__].content__, 0);
		mem__->clean((unsigned char [1]){mem_ptr}, none, \
					token__->content__[i__], 0);
		++i__;
	}
	mem__->clean((unsigned char [1]){mem_ptr}, none, \
				token__, token_size_);
}

#endif
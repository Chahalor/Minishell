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

#ifndef TOKEN___C
# define TOKEN___C

/* -------- modules --------- */
	// ---- access ----- //
# include "tokenizer__.h"

/* -------- inlines --------- */

// doc ...
__attribute__((always_inline, used))
//	(-internal-)
extern inline char	__tokenize(\
	t_token_ **token__
	const t_mem *restrict const mem__,
	const char **argv__,
	const unsigned int argc__
)	// v.1. >>> tag: def->_tokenize
{
	if (unexpet(\
			_token_setup(token__, argv__, argc__) \
			!= no_error))
		return (failed_to_setup);
	__token_parse(argv__, argc__);
	return (no_error);
}

#endif
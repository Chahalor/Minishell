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
	t_token_ **token__,
	const char *restrict const cmd__
)	// v.1. >>> tag: def->_tokenize
{
	_token_unload();
	if (unexpet(\
			_token_setup(token__, cmd__) \
			!= no_error))
		return (failed_to_setup);
	_token_parse(cmd__);
	return (no_error);
}

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser__.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/06/25 15:45:12 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER__C
# define PARSER__C

/* -------- modules --------- */
	// ---- access ----- //
# include "tokenizer_.h"

/* -------- inlines --------- */

// doc ...
__attribute__((always_inline, used))
//	(-private-)
extern inline void	_token_parse(\
	const char **argv_,
	const unsigned int argc_
)	// v.1. >>> tag: exp->_token_parse
{
	return (__token_parse(\
				(t_token__ *)&_token_self()->_internal_, \
				(t_mem *)&_manager()->mem, \
				argv_, argc_));
}

#endif
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

#ifndef SETUP__C
# define SETUP__C

/* -------- modules --------- */
	// ---- access ----- //
# include "tokenizer_.h"

/* -------- inlines --------- */

// doc ...
__attribute__((always_inline, used))
//	(-private-)
extern inline char	_token_setup(\
	const char *restrict const cmd_
)	// v.1. >>> tag: exp->_token_setup
{
	return (__token_setup(\
				(t_token__ *)&_token_self()->_internal_, \
				(t_mem *)&_manager()->mem, \
				cmd_));
}

#endif
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

#ifndef TOKEN__C
# define TOKEN__C

/* -------- modules --------- */
	// ---- access ----- //
# include "tokenizer_.h"

/* ------- functions -------- */

// doc ...
__attribute__((hot, used))
//	(-private-)
extern char	_tokenize(\
	const char **argv_,
	const unsigned int argc_
)	// v.1. >>> tag: exp->_tokenize
{
	t_token_	*token__;

	token__ = (t_token__ *)&_token_self()->_internal_;
	return (_tokenize(&token__, (t_mem *)&_manager()->mem, argv_, argc_));
}

#endif
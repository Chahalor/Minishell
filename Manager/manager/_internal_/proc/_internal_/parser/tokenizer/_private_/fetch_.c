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

#ifndef FETCH__C
# define FETCH__C

/* -------- modules --------- */
	// ---- access ----- //
# include "tokenizer_.h"

/* ------- functions -------- */

// doc ...
__attribute__((hot, used))
//	(-private-)
extern t_token_object_	*_token_fetch(\
	const unsigned char mode_
)	// v.1. >>> tag: exp->_token_fetch
{
	return (__token_fetch((t_token__ *)&_token_self()->_internal_, mode_));
}

#endif
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

#ifndef ACCESS__C
# define ACCESS__C

/* -------- modules --------- */
	// ---- access ----- //
# include "parse_.h"

/* ------- functions -------- */

// doc ...
__attribute__((hot, used))
// (-private-)
extern t_parse_	*_parse_get(\
	t_parse_	*restrict const new_
)	// v.1. >>> tag: exp->_parse_get
{
	return (__parse_get(new_));
}

// doc ...
__attribute__((hot, used))
// (-private-)
extern t_parse_	*_parse_self(void)	// v.1. >>> tag: exp->_parse_self
{
	return (__parse_self());
}

#endif
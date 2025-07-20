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

#ifndef ACCESS__C
# define ACCESS__C

/* -------- modules --------- */
	// ---- access ----- //
# include "reader_.h"

/* ------- functions -------- */

// doc ...
__attribute__((hot, used))
// (-private-)
extern t_reader_	*_reader_get(\
	t_reader_	*restrict const new_
)	// v.1. >>> tag: exp->_reader_get
{
	return (__reader_get(new_));
}

// doc ...
__attribute__((hot, used))
// (-private-)
extern t_reader_	*_reader_self(void)	// v.1. >>> tag: exp->_reader_self
{
	return (_reader_self());
}

#endif
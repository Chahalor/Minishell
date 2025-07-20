/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _history.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/05/23 10:59:17 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIND__C
# define FIND__C

/* -------- modules --------- */
	// ---- access ----- //
# include "history_.h"

/* ------- functions -------- */

// doc ...
__attribute__((hot, used))
//	(-private-)
extern char	_histo_find(\
	const unsigned int index_
)	// v.1. >>> tag: exp->_histo_find
{
	return (_histo_find((t_histo *)&_histo_self()->_internal_, index_));
}

#endif
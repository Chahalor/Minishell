/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove__.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/06/27 13:51:57 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REMOVE__C
# define REMOVE__C

/* -------- modules --------- */
	// ---- access ----- //
# include "reader_.h"

/* ------- functions -------- */

// doc ...
__attribute__((cold, used))
// (-private-)
extern char	_reader_remove_container(\
	const unsigned int target_
)	// v.1. >>> tag: exp->_reader_remove_container
{
	return (_reader_remove_container(\
				(t_reader__ *)&_reader_self()->_internal_,
				(t_mem *)&manager()->mem, target_));
}

#endif
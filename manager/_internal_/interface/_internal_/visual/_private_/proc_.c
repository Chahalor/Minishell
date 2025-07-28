/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init__.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/06/25 15:06:11 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROC__C
# define PROC__C

/* -------- modules --------- */
	// ---- access ----- //
# include "visual_.h"

/* -------- inlines --------- */

// doc ...
__attribute__((always_inline, used))
// (-private-)
extern inline int	_visual_proc(\
	const char *restrict const str_,
	va_list args_
)	// v.1. >>> tag: exp->_visual_proc
{
	return (__visual_proc((t_visual__ *)&_visual_self()->_internal_, \
						(t_mem *)&_manager()->mem, str_, args_));
}

/* ------- functions -------- */

// doc ...
__attribute__((hot, used))
// (-private-)
extern int	_visual_select(\
	const char *restrict const str_,
	va_list args_
)	// v.1. >>> tag: exp->_visual_select
{
	return (__visual_select((t_visual__ *)&_visual_self()->_internal_, \
							str_, args_));
}

#endif
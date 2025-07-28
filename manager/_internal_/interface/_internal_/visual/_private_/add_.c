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

#ifndef ADD__C
# define ADD__C

/* -------- modules --------- */
	// ---- access ----- //
# include "visual_.h"

/* -------- inlines --------- */

// doc ...
__attribute__((always_inline, used))
// (-private-)
extern inline int	_visual_str(\
	const char *restrict const str_
)	// v.1. >>> tag: exp->_visual_str
{
	return (__visual_str((t_visual__ *)&_visual_self()->_internal_, str_));
}

// doc ...
__attribute__((always_inline, used))
// (-private-)
extern inline int	_visual_hex(\
	unsigned long val_,
	const char *const restrict base_
)	// v.1. >>> tag: exp->_visual_hex
{
	return (__visual_str((t_visual__ *)&_visual_self()->_internal_, \
						val_, base_));
}

// doc ...
__attribute__((always_inline, used))
// (-private-)
extern inline int	_visual_ptr(\
	const void *restrict const ptr_
)	// v.1. >>> tag: exp->_visual_ptr
{
	return (__visual_str((t_visual__ *)&_visual_self()->_internal_, \
						ptr_));
}

// doc ...
__attribute__((always_inline, used))
// (-private-)
extern inline int	_visual_dec(\
	long val_
)	// v.1. >>> tag: exp->_visual_dec
{
	return (__visual_dec((t_visual__ *)&_visual_self()->_internal_, \
						val_));
}

// doc ...
__attribute__((hot, used))
// (-private-)
extern int	_visual_add(\
	const char ltr_
)	// v.1. >>> tag: exp->_visual_add
{
	return (__visual_dec((t_visual__ *)&_visual_self()->_internal_, \
						ltr_));
}

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/06/20 11:31:56 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORMAT__C
# define FORMAT__C

/* -------- modules --------- */
	// ---- access ----- //
# include "memory_.h"

/* ------- functions -------- */

// doc ...
__attribute__((hot, used))
//	(-private-)
extern unsigned int	_mem_format(\
	const unsigned char *restrict const mode_,
	void *area_,
	const unsigned int index_
)	// v.1. >>> tag: exp->_mem_format
{
	return ((char)__mem_format(\
				(t_mem__ *)_mem_self()->_internal_, mode_, area_, index_));
}

// doc ...
__attribute__((hot, used))
//	(-private-)
extern unsigned int	_mem_format_collide(\
	const t_mem__ *restrict const mem_,
	void *area_,
	const unsigned int index_
)	// v.1. >>> tag: exp->_mem_format_collide
{
	return ((void)mem_, __mem_format_collide((unsigned char *)area_, index_));
}

// doc ...
__attribute__((hot, used))
//	(-private-)
extern unsigned int	_mem_format_correspond(\
	const t_mem__ *restrict const mem_,
	void *area_,
	const unsigned int index_
)	// v.1. >>> tag: exp->_mem_format_correspond
{
	return (__mem_format_correspond(mem_, (unsigned char *)area_, index_));
}

#endif
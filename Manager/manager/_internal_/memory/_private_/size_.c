/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/06/24 16:23:40 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIZE__C
# define SIZE__C

/* -------- modules --------- */
	// ---- access ----- //
# include "memory_.h"

/* ------- functions -------- */

// doc ...
__attribute__((hot, used))
//	(-private-)
extern unsigned int	_mem_size(\
	const unsigned char *restrict const mode_,
	void *area_,
	const char *restrict const end_
)	// v.1. >>> tag: exp->_mem_size
{
	return (__mem_size(mode_, area_, end_));
}

// doc ...
__attribute__((hot, used))
//	(-private-)
extern unsigned int	_mem_word_len(\
	void *area_,
	const char *restrict const end_
)	// v.1. >>> tag: exp->_mem_word_len
{
	return (__mem_word_len(area_, end_));
}

// doc ...
__attribute__((hot, used))
//	(-private-)
extern unsigned int	_mem_len(\
	void *area_,
	const char *restrict const end_
)	// v.1. >>> tag: exp->_mem_len
{
	return (__mem_len(area_, end_));
}

#endif
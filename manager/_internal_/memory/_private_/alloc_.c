/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/06/19 17:39:52 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALLOC__C
# define ALLOC__C

/* -------- modules --------- */
	// ---- access ----- //
# include "memory_.h"

/* ------- functions -------- */

// doc ...
__attribute__((hot, used))
//	(-private-)
extern char	_mem_alloc(\
	const unsigned char *restrict const mode_,
	void **ptr_,
	const unsigned int size_,
	const unsigned char type_
)	// v.1. >>> tag: exp->_mem_alloc
{
	return (__mem_alloc(mode_, ptr_, size_, type_));
}

// doc ...
__attribute__((hot, used))
//	(-private-)
extern char	_mem_alloc_new(\
	void **ptr_,
	const unsigned int size_,
	const unsigned char type_
)	// v.1. >>> tag: exp->_mem_alloc_new
{
	return (__mem_alloc_new(ptr_, size_, type_));
}

// doc ...
__attribute__((hot, used))
//	(-private-)
extern char	_mem_realloc(\
	void **ptr_,
	const unsigned int size_,
	const unsigned char type_
)	// v.1. >>> tag: exp->mem_realloc
{
	return ((void)type_, __mem_realloc(ptr_, size_));
}

#endif
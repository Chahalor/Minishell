/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/06/26 13:19:11 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLEAN__C
# define CLEAN__C

/* -------- modules --------- */
	// ---- access ----- //
# include "memory_.h"

/* ------- functions -------- */

// doc ...
__attribute__((hot, used))
//	(-private-)
extern char	_mem_clean(\
	const unsigned char *restrict const mode_,
	const char code_,
	void *ptr_,
	const unsigned int size_
)	// v.1. >>> tag: exp->_mem_clean
{
	return (__mem_clean(mode_, code_, ptr_, size_));
}

// doc ...
__attribute__((hot, used))
//	(-private-)
extern char	_mem_clean_buffer(\
	const char code_,
	void *ptr_,
	const unsigned int size_
)	// v.1. >>> tag: exp->_mem_clean_buffer
{
	return ((void)code_, __mem_clean_buffer(ptr_, size_));
}

// doc ...
__attribute__((hot, used))
//	(-private-)
extern char	_mem_clean_ptr(\
	const char code_,
	void *ptr_,
	const unsigned int size_
)	// v.1. >>> tag: exp->_mem_clean_ptr
{
	return ((void)code_, __mem_clean_ptr(ptr_, size_));
}

// doc ...
__attribute__((destructor, cold, used))
//	(-private-)
extern char	_mem_clean_all(\
	const char code_,
	void *ptr_,
	const unsigned int size_
)	// v.1. >>> tag: exp->_mem_clean_all
{
	return ((void)size_, __mem_clean_all(code_, ptr_));
}

#endif
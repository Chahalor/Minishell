/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean__.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/06/20 13:00:34 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLEAN___C
# define CLEAN___C

/* -------- modules --------- */
	// ---- access ----- //
# include "memory__.h"

/* -------- inlines --------- */

// doc ...
__attribute__((always_inline, used))
// (-internal-)
extern inline char	__mem_clean_buffer(\
	void *ptr__,
	const unsigned int size__
)	// v.1. >>> tag: def->mem_clean_buffer
{
	volatile unsigned long long	*restrict	area_64b__;
	volatile unsigned char	*restrict		area_8b__;
	const unsigned int						len_64b__ = (size__ >> 3);
	register unsigned int					i__;

	area_64b__ = (volatile unsigned long long *)ptr__;
	i__ = 0;
	while (i__++ != len_64b__)
		*(area_64b__++) = 0;
	i__ <<= 3;
	area_8b__ = (volatile unsigned char *)ptr__ + i__;
	while (i__++ != size__)
		*(area_8b__++) = 0;
	return (no_error);
}

// doc ...
__attribute__((always_inline, used))
// (-internal-)
extern inline char	__mem_clean_ptr(\
	void *ptr__,
	const unsigned int size__
)	// v.1. >>> tag: def->mem_clean_ptr
{
	t_mem_alloc_	*restrict	alloc__;

	alloc__ = _mem_to_alloc(ptr__);
	if (unexpect(!alloc__))
		return (mem_rewinding_failure_);
	_mem_manage((unsigned char [1]){mem_drop_}, ptr__, size__);
	return (free(alloc__), no_error);
}

// doc ...
__attribute__((always_inline, used))
// (-internal-)
extern inline char	__mem_clean_all(\
	const char code__,
	void *ptr__
)	// v.1. >>> tag: def->mem_clean_all
{
	(void)ptr__;
	return (exit(code__), no_error);
}

// doc ...
__attribute__((always_inline, used))
// (-internal-)
extern inline char	__mem_clean(\
	const unsigned char *restrict const mode__,
	const char code__,
	void *ptr__,
	const unsigned int size__
)	// v.1. >>> tag: def->mem_clean
{
	return ((t_mem_clean_func_ [3]){\
				_mem_clean_buffer, _mem_clean_ptr, _mem_clean_all}[\
					mode__[0]](code__, ptr__, size__));
}

#endif
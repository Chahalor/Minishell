/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read__.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/06/20 13:01:31 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ___C
# define READ___C

/* -------- modules --------- */
	// ---- access ----- //
# include "memory__.h"

/* -------- inlines --------- */

// doc ...
__attribute__((always_inline, used))
// (-internal-)
extern inline char	__mem_read_buffer(\
	const unsigned char spec__,
	void *src__,
	void *dest__,
	const unsigned int len__
)	// v.1. >>> tag: def->mem_read_buffer
{
	t_mem_alloc_	*restrict	alloc__;
	void						*lwall__;
	void						*rwall__;

	alloc__ = _mem_to_alloc(src__);
	if (unexpect(!alloc__))
		return (mem_rewinding_failure_);
	lwall__ = &alloc__->lborder__[3];
	if (unexpect(src__ <= lwall__))
		src__ = alloc__->buffer__;
	rwall__ = &alloc__->rborder__[0];
	if (unexpect((void *)((char *)src__ + len__) >= rwall__))
		return (mem_frontier_smashing_);
	if (spec__ != mem_test_)
		return (_mem_copy((unsigned char [1]){mem_raw_}, src__, dest__, len__));
	return (no_error);
}

// doc ...
__attribute__((always_inline, used))
// (-internal-)
extern inline char	__mem_read_file(\
	void *src__,
	void *dest__,
	const unsigned int len__
)	// v.1. >>> tag: def->mem_read_file
{
	(void)src__;
	(void)dest__;
	(void)len__;
	return (no_error);
}

// doc ...
__attribute__((always_inline, used))
// (-internal-)
extern inline char	__mem_read(\
	const unsigned char *restrict const mode__,
	void *src__,
	void *dest__,
	const unsigned int len__
)	// v.1. >>> tag: def->mem_read
{
	return ((t_mem_read_func_ [2]){\
				_mem_read_buffer, _mem_read_file}[\
					mode__[0]](mode__[1], src__, dest__, len__));
}

#endif
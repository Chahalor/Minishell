/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc__.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/06/20 13:55:14 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALLOC___C
# define ALLOC___C

/* -------- modules --------- */
	// ---- access ----- //
# include "memory__.h"

/* -------- inlines --------- */

// doc ...
__attribute__((always_inline, used))
// (-internal-)
extern inline char	__mem_alloc_new(\
	void **ptr__,
	const unsigned int size__,
	const unsigned char type__
)	// v.1. >>> tag: def->mem_alloc_new
{
	t_mem_alloc_	*restrict	alloc__;
	void						*base__;

	alloc__ = (void *)malloc(mem_alloc_size__ + size__ + sizeof(void *));
	if (unexpect(!alloc__))
		return (mem_allocation_failure_);
	base__ = (void *)((char *)alloc__ + mem_buffer_offset__);
	*alloc__ = (t_mem_alloc_){\
		.size__ = size__, \
		.type__ = type__, \
		.buffer__ = _mem_section((void **)&base__, size__), \
		.id__ = _mem_manage((unsigned char [2]){mem_add_, type__}, \
							alloc__, size__) \
	};
	_mem_clean((unsigned char [1]){mem_buffer_}, none, alloc__->lborder__, 4);
	_mem_clean((unsigned char [1]){mem_buffer_}, none, \
				alloc__->buffer__, size__);
	_mem_clean((unsigned char [1]){mem_buffer_}, none, alloc__->rborder__, 4);
	return ((void)(*ptr__ = alloc__->buffer__), no_error);
}

// doc ...
__attribute__((always_inline, used))
// (-internal-)
extern inline char	__mem_realloc(\
	void **ptr__,
	const unsigned int size__
)	// v.1. >>> tag: def->mem_realloc
{
	t_mem_alloc_	*restrict	alloc__;
	void			*restrict	temp__;
	unsigned char				code__;
	unsigned char				type__;

	alloc__ = _mem_to_alloc(*ptr__);
	code__ = no_error;
	if (unexpect(!ptr__))
		code__ = mem_untracked_data_expired_;
	else if (unexpect(!alloc__))
		return (mem_rewinding_failure_);
	type__ = mem_string_;
	if (expect(!code__))
		type__ = alloc__->type__;
	if (unexpect(\
			_mem_alloc((unsigned char [1]){mem_new_}, (void **)&temp__, \
						size__, type__) != no_error))
		return (mem_reallocation_failure_);
	if (expect(!code__))
	{
		_mem_copy((unsigned char [1]){mem_raw_}, ptr__, \
					temp__, alloc__->size__);
		code__ = _mem_manage((unsigned char [1]){mem_drop_}, *ptr__, size__);
	}
	return ((void)(*ptr__ = temp__), code__);
}

// doc ...
__attribute__((always_inline, used))
// (-internal-)
extern inline char	__mem_alloc(\
	const unsigned char *restrict const mode__,
	void **ptr__,
	const unsigned int size__,
	const unsigned char type__
)	// v.1. >>> tag: def->mem_alloc
{
	return ((t_mem_alloc_func_ [2]){\
				_mem_alloc_new, _mem_realloc}[\
					mode__[0]](ptr__, size__, type__));
}

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add__.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/06/27 13:45:59 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ADD___C
# define ADD___C

/* -------- modules --------- */
	// ---- access ----- //
# include "reader__.h"

/* -------- inlines --------- */

// doc ...
__attribute__((always_inline, used))
// (-internal-)
extern inline char	__reader_add_container(\
	const t_reader__ *restrict const reader__,
	const t_mem *restrict const mem__,
	const unsigned int target__,
	void **buffer__
)	// v.1. >>> tag: def->_reader_add_container
{
	t_container_		*container__;
	t_container_		*entrypoint__;
	void				*base__;
	const unsigned int	size__ = reader_container_size_ + READ_BUFFER_SIZE;

	if (unexpect(\
			mem__->alloc((unsigned char [1]){mem_new}, (void **)&container__, \
						size__, mem_buffer) \
			!= no_error))
		return (error);
	base__ = (void *)((char *)container__ + reader_container_size_);
	container__->target__ = target__;
	container__->size__ = READ_BUFFER_SIZE;
	container__->buffer__ = mem__->section((void **)&base__, READ_BUFFER_SIZE);
	if (unexpect(\
			_reader_find((unsigned char [1]){reader_container_}, \
						(char *)0, (void **)&entrypoint__) \
			!= no_error))
		return (mem__->clean((unsigned char [1]){mem_ptr}, reader_gate_burst_, \
							container__, size__));
	entrypoint__->gate__ = container__;
	++reader__->size__;
	++reader__->qty__;
	return ((void)(*buffer__ = container__), no_error);
}

#endif
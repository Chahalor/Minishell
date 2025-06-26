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

#ifndef INIT___C
# define INIT___C

/* -------- modules --------- */
	// ---- access ----- //
# include "memory__.h"

/* -------- inlines --------- */

// doc ...
__attribute__((always_inline, used))
// (-internal-)
extern inline char	__mem_init(\
	t_mem_ *restrict const mem__
)	// v.1. >>> tag: def->mem_init
{
	*mem__ = (t_mem_){\
		.alloc_ = _mem_alloc, \
		.clean_ = _mem_clean, \
		.size_ = _mem_size, \
		.section_ = _mem_section, \
		.write_ = _mem_write, \
		.read_ = _mem_read, \
		.copy_ = _mem_copy, \
		.shift_ = _mem_shift, \
		.compare_ = _mem_compare, \
		.search_ = _mem_search \
	};
	if (unexpect(!_mem_get(mem__)))
		return (failed_to_setup);
	return (no_error);
}

#endif
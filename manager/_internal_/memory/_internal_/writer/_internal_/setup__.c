/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read__.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/06/27 16:49:54 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETUP___C
# define SETUP___C

/* -------- modules --------- */
	// ---- access ----- //
# include "writer__.h"

/* -------- inlines --------- */

// doc ...
__attribute__((always_inline, used))
//	(-internal-)
extern inline char	__writer_setup(\
	t_writer_ **writer__,
	const t_mem *restrict const mem__
)	// v.1. >>> tag: def->writer_setup
{
	if (unexpect(\
			mem__->alloc((unsigned char [1]){mem_new}, (void **)writer__, \
						sizeof(t_writer_), mem_buffer)
			!= no_error))
		return (failed_to_setup);
	return (_writer_init(*writer__));
}

#endif
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
# include "reader__.h"

/* -------- inlines --------- */

// doc ...
__attribute__((always_inline, used))
//	(-internal-)
extern inline char	__reader_setup(\
	t_reader_ **reader__,
	const t_mem *restrict const mem__
)	// v.1. >>> tag: def->reader_setup
{
	if (unexpect(\
			mem__->alloc((unsigned char [1]){mem_new}, (void **)reader__, \
						reader_size_, mem_buffer)
			!= no_error))
		return (failed_to_setup);
	return (_reader_init(*reader__));
}

#endif
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

#ifndef SETUP___C
# define SETUP___C

/* -------- modules --------- */
	// ---- access ----- //
# include "memory__.h"

/* -------- inlines --------- */

// doc ...
__attribute__((always_inline, used))
// (-internal-)
extern inline char	__mem_setup(\
	t_mem_ **mem__
)	// v.1. >>> tag: def->mem_setup
{
	if (unexpect(\
			_mem_alloc((unsigned char [1]){mem_new}, (void **)mem__, \
						sizeof(t_mem_), mem_buffer)
			!= no_error))
		return (mem_allocation_failure_);
	return (_mem_init(*mem__));
}

#endif
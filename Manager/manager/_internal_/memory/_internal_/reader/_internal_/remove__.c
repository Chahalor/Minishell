/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove__.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/06/27 13:51:57 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REMOVE___C
# define REMOVE___C

/* -------- modules --------- */
	// ---- access ----- //
# include "reader__.h"

/* -------- inlines --------- */

// doc ...
__attribute__((always_inline, used))
// (-internal-)
extern inline char	__reader_remove_container(\
	const t_reader__ *restrict const reader__,
	const t_mem *restrict const mem__,
	const unsigned int target__
)	// v.1. >>> tag: def->_reader_remove_container
{
	t_container__	*container__;
	char			code__;

	if (unexpect(\
			_reader_find((unsigned char [1]){reader_container_}, \
						(char *)target__, (void**)&container__) \
			!= no_error))
		return (reader_not_registered_);
	reader__->qty__--;
	return (mem__->clean((unsigned char [1]){mem_buffer}, \
							no_error, (void **)&container__, \
							reader_container_size_ + container__->size__));
}

#endif
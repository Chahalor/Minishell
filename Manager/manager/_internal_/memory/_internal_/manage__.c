/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage__.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/06/20 10:51:52 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MANAGE___C
# define MANAGE___C

/* -------- modules --------- */
	// ---- access ----- //
# include "memory__.h"

/* -------- inlines --------- */

// doc ...
__attribute__((always_inline, used))
// (-internal-)
extern inline int	__mem_manage(\
	t_mem__ *restrict const mem__,
	const unsigned char *restrict const mode__,
	void *area__,
	const unsigned int size__
)	// v.1. >>> .
{
	int	index__;

	if (mode__[0] == mem_add_ && mode__[1] != mem_self_)
	{
		mem__->total__ += size__;
		if (unexpect(mem__->index__ >= mem__->size__))
		{
			if (unexpect(\
					_mem_alloc((unsigned char [1]){mem_re}, mem__->access__, \
								mem__->size__ << 1, mem_table) \
					!= no_error))
				return (_mem_clean((unsigned char [1]){mem_all}, \
									mem_allocation_failure_, NULL, 0));
			mem__->size <<= 1;
		}
		mem__->access__[mem__->index__] = area__;
		return (mem__->index__++);
	}
	else if (mode__[0] == mem_keep_)
	{
		index__ = _mem_search((unsigned char [2]){mem_keep_, mem_empty_}, \
							NULL, NULL);
		if (index__ != -1)
		{
			mem__->free__[index__] = size__;
			mem__->pool__[index__] = area__;
		}
	}
	else if (mode__[0] == mem_drop_)
	{
		index__ = _mem_search((unsigned char [1]){mem_data_}, \
							mem__->access__, area__);
		mem__->access__[index__] = NULL;
		mem__->total__ -= size__;
	}
	return (0);
}

#endif
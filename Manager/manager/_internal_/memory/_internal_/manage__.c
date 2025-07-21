/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage__.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Delta_0ne <romain.creuzeau.pro@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/07/21 13:03:46 by Delta_0ne        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MANAGE___C
# define MANAGE___C

/* -------- modules --------- */
	// ---- access ----- //
# include "memory__.h"

/* -------- inlines --------- */

// TODO: modify this shitty function as it does almost no fucking checks when,
// saying it's been allocated and when we drop the block.

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

	if (mode__[0] == mem_add_)
	{
		mem__->total__ += size__;
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
		else
			_mem_clean((unsigned char [1]){mem_ptr}, none, area__, size__);
	}
	else if (mode__[0] == mem_drop_)
		mem__->total__ -= size__;
	return (0);
}

#endif
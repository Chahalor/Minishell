/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift__.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/06/27 14:20:12 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPLIT___C
# define SPLIT___C

/* -------- modules --------- */
	// ---- access ----- //
# include "memory__.h"

/* -------- inlines --------- */

// doc ...
__attribute__((always_inline, used))
// (-internal-)
extern inline char	**__mem_split(\
	const char *area__,
	const char sep__
)	// v.1. >>> tag: def->_mem_split
{
	char					**copy__;
	unsigned int			seg__;
	unsigned int			size__;
	unsigned int			index__;
	register unsigned int	i__;

	seg__ = 0;
	size__ = _mem_size((unsigned char [1]){mem_len_}, area__, 0);
	index__ = 0;
	while (index__ != size__ && ++seg__)
		index__ += _mem_shift((unsigned char [1]){mem_end_}, \
							area__ + index__, &sep__);
	if (unexpect(\
			_mem_alloc((unsigned char [1]){mem_new}, &copy__, \
						seg__ * sizeof(char *), mem_table_) \
			!= no_error))
		return (NULL);
	index__ = 0;
	i__ = 0;
	while (i__ != seg__)
	{
		size__ = _mem_shift((unsigned char [1]){mem_end_}, \
							area__ + index__, &sep__);
		index__ += size__;
		if (unexpect(\
				_mem_copy((unsigned char [1]){mem_duplicate_}, area__, \
						copy__[i__++], size__) \
				!= no_error))
			return (NULL);
	}
	return (copy__);
}

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search__.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/06/20 12:20:49 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEARCH___C
# define SEARCH___C

/* -------- modules --------- */
	// ---- access ----- //
# include "memory__.h"

/* -------- inlines --------- */

// doc ...
__attribute__((always_inline, used))
// (-internal-)
extern inline int	__mem_search_data(\
	const char *const area__,
	const char *const target__
)	// v.1. >>> tag: def->mem_search_data
{
	const unsigned int		area_size__ = (\
		_mem_size((unsigned char [1]){mem_len_}, (void *)area__, '\0'));
	const unsigned int		target_size__ = (\
		_mem_size((unsigned char [1]){mem_len_}, (void *)target__, '\0'));
	register unsigned int	i__;
	unsigned int			j__;

	i__ = 0;
	while (i__ != area_size__ && (area_size__ - i__) > target_size__)
	{
		j__ = target_size__;
		if (unexpect(_mem_compare(area__, target__, &j__)))
			return (i__);
		i__ += j__ + 1;
	}
	return (-1);
}

// doc ...
__attribute__((always_inline, used))
// (-internal-)
extern inline int	__mem_search_keep(\
	const t_mem__ *restrict const mem__,
	const unsigned char *restrict const mode__,
	const unsigned int size__
)	// v.1. >>> tag: def->mem_search_keep
{
	register int	i__;

	i__ = -1;
	if (mode__[1] == mem_empty_)
	{
		while (++i__ != 10)
			if (!mem__->free__[i__])
				return (i__);
	}
	else if (mode__[1] == mem_free_)
	{
		while (++i__ != 10)
			if (mem__->free__[i__] >= size__)
				return (i__);
	}
	return (-1);
}

// doc ...
__attribute__((always_inline, used))
// (-internal-)
extern inline int	__mem_search_file(\
	const t_mem_ *restrict const mem__,
	const unsigned char *restrict const mode__,
	const char *restrict const target__
)	// v.1. >>> tag: def->mem_search_file
{
	char	*fd__;

	if (unexpect(\
			mem__->reader.find((unsigned char [2]){reader_file, mode__[1]}, \
								target__, (void **)&fd__) \
			!= no_error))
		return (error);
	return ((int)fd__);
}

// doc ...
__attribute__((always_inline, used))
// (-internal-)
extern inline int	__mem_search(\
	const unsigned char *restrict const mode__,
	const void *restrict const area__,
	const void *restrict const target__
)	// v.1. >>> tag: def->mem_search
{
	return ((t_mem_search_func_ [3]){\
				_mem_search_data, _mem_search_keep, _mem_search_file}[\
					mode__[0]](mode__, area__, target__));
}

#endif   
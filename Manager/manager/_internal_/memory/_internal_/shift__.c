/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift__.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/06/24 15:43:21 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHIFT___C
# define SHIFT___C

/* -------- modules --------- */
	// ---- access ----- //
# include "memory__.h"

/* -------- inlines --------- */

// doc ...
__attribute__((always_inline, used))
// (-internal-)
extern inline unsigned int	__mem_shift_by(\
	const unsigned char spec__,
	unsigned char *restrict const area__,
	const unsigned int shift__,
	const unsigned int len__
)	// v.1. >>> tag: def->mem_shift_by
{
	register unsigned int	i__;

	i__ = (shift__ >> !spec__);
	while (i__ != len__ - shift__)
	{
		area__[i__ + (shift__ >> !spec__)] = (\
			area__[i__ + (shift__ >> !!spec__)]);
		++i__;
	}
	return (_mem_clean((unsigned char [1]){mem_buffer_}, none, \
						area__ + (i__ >> !spec__), shift__), i__);
}

// doc ...
__attribute__((always_inline, used))
// (-internal-)
extern inline unsigned int	__mem_rewind(\
	const unsigned char *restrict const area__
)	// v.1. >>> tag: def->mem_rewind
{
	register unsigned int	i__;

	i__ = 0;
	while (i__ != 1024)
	{
		if (unexpect(!area__[-i__] \
				&& _mem_format((unsigned char [1]){mem_correspond_}, \
								(void *)area__, i__)))
			return (i__ + mem_alloc_offset__);
		++i__;
	}
	return (0);
}

// doc ...
__attribute__((always_inline, used))
// (-internal-) x (-local-)
extern inline unsigned int	__mem_avoid_group(\
	const unsigned char *restrict const area__,
	const unsigned char *restrict const end__
)	// v.1. >>> .
{
	register unsigned int	i__;
	register unsigned int	j__;

	i__ = 0;
	while (area__[i__])
	{
		j__ = 0;
		while (end__[j__])
		{
			if (area__[i__] == end__[j__])
				break ;
			++j__;
		}
		++i__;
	}
	return (i__);
}

// doc ...
__attribute__((always_inline, used))
// (-internal-)
extern inline unsigned int	__mem_avoid_by(\
	const unsigned char target__,
	const unsigned char *restrict const area__,
	const unsigned char *restrict const end__
)	// v.1. >>> tag: def->mem_avoid_by
{
	register unsigned int	i__;

	i__ = 0;
	if (target__ == mem_empty_)
		while (!area__[i__] && i__ != end__)
			++i__;
	else if (target__ == mem_blank_)
		while (area__[i__] && i__ != end__ \
				&& ((area__[i__] == 32 || area__[i__] >= 9) \
					&& area__[i__] <= 13))
			++i__;
	else if (target__ == mem_plain_)
		while (area__[i__] && i__ != end__ \
				&& (!(area__[i__] == 32 || area__[i__] >= 9) \
					&& area__[i__] <= 13))
			++i__;
	else if (target__ == mem_group_)
		return (__mem_avoid_group(area__, end__));
	else if (target__ == mem_end_)
		while (area__[i__] && area__[i__] != *end__)
			++i__;
	return (i__);
}

// doc ...
__attribute__((always_inline, used))
// (-internal-)
extern inline unsigned int	__mem_shift(\
	const unsigned char *restrict const mode__,
	void *restrict const area__,
	const char *restrict const val__
)	// v.1. >>> tag: def->mem_shift
{
	return ((t_mem_shift_func_ [3]){\
				_mem_shift_by, _mem_avoid_by, _mem_rewind}[\
					mode__[0]](mode__[1], area__, val__));
}

#endif 
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare__.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/06/19 17:38:55 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPARE___C
# define COMPARE___C

/* -------- modules --------- */
	// ---- access ----- //
# include "memory__.h"

/* -------- inlines --------- */

// doc ...
__attribute__((always_inline, used))
// (-internal-) x (-local-)
static inline unsigned char	__mem_compare_8b(\
	const char *const area__,
	const char *const target__,
	const unsigned int size__,
	unsigned int *index__
)	// v.1. >>> .
{
	register unsigned int	i__;

	i__ = 0;
	while (i__ != size__ && (area__[i__] == target__[i__]))
		++i__;
	*index__ += i__;
	if (unexpect(i__ == size__))
		return (TRUE);
	return (FALSE);
}

// doc ...
__attribute__((always_inline, used))
// (-internal-) x (-local-)
static inline unsigned char	__mem_compare_16b(\
	const unsigned short *const area__,
	const unsigned short *const target__,
	const unsigned int size__,
	unsigned int *index__
)	// v.1. >>> .
{
	register unsigned int	i__;

	i__ = 0;
	while (i__ != size__ && (area__[i__] == target__[i__]))
		++i__;
	*index__ += i__;
	if (unexpect(i__ == size__))
		return (TRUE);
	return (FALSE);
}

// doc ...
__attribute__((always_inline, used))
// (-internal-) x (-local-)
static inline unsigned char	__mem_compare_32b(\
	const unsigned int *const area__,
	const unsigned int *const target__,
	const unsigned int size__,
	unsigned int *index__
)	// v.1. >>> .
{
	register unsigned int	i__;

	i__ = 0;
	while (i__ != size__ && (area__[i__] == target__[i__]))
		++i__;
	*index__ += i__;
	if (unexpect(i__ == size__))
		return (TRUE);
	return (FALSE);
}

// doc ...
__attribute__((always_inline, used))
// (-internal-) x (-local-)
static inline unsigned char	__mem_compare_64b(\
	const unsigned long long *const area__,
	const unsigned long long *const target__,
	const unsigned int size__,
	unsigned int *index__
)	// v.1. >>> .
{
	register unsigned int	i__;

	i__ = 0;
	while (i__ != size__ && (area__[i__] == target__[i__]))
		++i__;
	*index__ += i__;
	if (unexpect(i__ == size__))
		return (TRUE);
	return (FALSE);
}

// doc ...
__attribute__((always_inline, used))
// (-internal-)
extern inline char	__mem_compare(\
	const char *const area__,
	const char *const target__,
	unsigned int *len__
)	// v.1. >>> tag: def->mem_compare
{
	unsigned int	i__;

	i__ = 0;
	if (area__[0] == target__[0] && (\
			__mem_compare_64b((unsigned long long *)((char *)area__), \
					(unsigned long long *)target__, \
					(*len__ & ~7u) >> 3, &i__) \
			|| __mem_compare_32b((unsigned int *)((char *)area__ + i__), \
					(unsigned int *)((char *)target__ + i__), \
					((*len__ - i__) & ~3u) >> 2, &i__) \
			|| __mem_compare_16b((unsigned short *)((char *)area__ + i__), \
					(unsigned short *)((char *)target__ + i__), \
					((*len__ - i__) & ~1u) >> 1, &i__) \
			|| __mem_compare_8b(area__ + i__, target__ + i__, \
					*len__ - i__, &i__)
		))
		return ((void)(*len__ = i__), TRUE);
	return ((void)(*len__ = i__), FALSE);
}

#endif
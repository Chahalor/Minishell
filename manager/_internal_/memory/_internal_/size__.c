/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size__.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/06/24 16:26:50 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIZE___C
# define SIZE___C

/* -------- modules --------- */
	// ---- access ----- //
# include "memory__.h"

/* -------- inlines --------- */

// doc ...
__attribute__((always_inline, used))
// (-internal-)
extern inline unsigned int	__mem_len(\
	void *area__,
	const char *restrict const end__
)	// v.1. >>> tag: def->_mem_len
{
	return (_mem_shift((unsigned char [2]){mem_spec_, mem_end_}, \
				area__, end__));
}


// doc ...
__attribute__((always_inline, used))
// (-internal-)
extern inline unsigned int	__mem_word_len(\
	void *area__,
	const char *restrict const end__
)	// v.1. >>> tag: def->_mem_word_len
{
	unsigned int	len__;

	len__ = _mem_shift((unsigned char [2]){mem_spec_, mem_group_}, \
						area__, end__);
	len__ -= (len__ - _mem_shift(\
							(unsigned char [2]){mem_spec_, mem_blank_}, \
							area__, '\0'));
	return (len__);
}

// doc ...
__attribute__((always_inline, used))
// (-internal-)
extern inline unsigned int	__mem_size(\
	const unsigned char *restrict const mode__,
	void *area__,
	const char *restrict const end__
)	// v.1. >>> tag: def->_mem_size
{
	return ((t_mem_size_func [2]){\
				_mem_len, _mem_word_len}[\
					mode__[0]](area__, end__));
}

#endif
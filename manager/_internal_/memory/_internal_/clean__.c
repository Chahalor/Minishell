/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean__.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/06/27 13:25:34 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLEAN___C
# define CLEAN___C

/* -------- modules --------- */
	// ---- access ----- //
# include "memory__.h"

/* -------- inlines --------- */

// doc ...
__attribute__((always_inline, used))
// (-internal-)
extern inline char	__mem_clean_buffer(\
	const char code__,
	void *ptr__,
	const unsigned int size__
)	// v.1. >>> tag: def->mem_clean_buffer
{
	volatile unsigned long long	*restrict	area_64b__;
	volatile unsigned char	*restrict		area_8b__;
	const unsigned int						len_64b__ = (size__ >> 3);
	register unsigned int					i__;

	area_64b__ = (volatile unsigned long long *)ptr__;
	i__ = 0;
	while (i__++ != len_64b__)
		*(area_64b__++) = 0;
	i__ <<= 3;
	area_8b__ = (volatile unsigned char *)ptr__ + i__;
	while (i__++ != size__)
		*(area_8b__++) = 0;
	return (code__);
}

// doc ...
__attribute__((always_inline, used))
// (-internal-)
extern inline char	__mem_clean_ptr(\
	const char code__,
	void *ptr__,
	const unsigned int size__
)	// v.1. >>> tag: def->mem_clean_ptr
{
	t_mem_alloc_	*restrict	alloc__;

	alloc__ = _mem_to_alloc(ptr__);
	if (unexpect(!alloc__))
		return (mem_rewinding_failure_);
	if (expect(ptr__ != _manager() && ptr__ != _mem_self()))
		_mem_manage((unsigned char [1]){mem_drop_}, ptr__, size__);
	else if (ptr__ == _manager())
	{
		free(alloc__);
		alloc__ = _mem_to_alloc(_mem_self());
		if (unexpect(!alloc__))
			return (mem_rewinding_failure_);
		return (free(alloc__), code__);
	}
	return (free(alloc__), code__);
}

// doc ...
__attribute__((always_inline, used))
// (-internal-)
extern inline char	__mem_clean_all(\
	t_mem__ *mem__,
	t_reader *restrict const reader__,
	const char code__
)	// v.1. >>> tag: def->mem_clean_all
{
	void						*manager__ = _manager();
	void						*memory__ = _mem_self();
	void						*ptr__;
	register unsigned int		i__;

	rl_reset_cmd();
	rl_clear_history();
	reader__->remove((unsigned char [1]){reader_all}, NULL);
	ptr__ = mem__->access__[0];
	i__ = 0;
	while (i__ != mem__->index__ - 1)
	{
		ptr__ = mem__->access__[i__++];
		if (expect(ptr__ && ptr__ != manager__ && ptr__ != memory__))
			free(ptr__);
	}
	return (exit(\
				_mem_clean((unsigned char [1]){mem_ptr}, code__, \
							manager__, 0)), \
			no_error);
}

// doc ...
__attribute__((always_inline, used))
// (-internal-)
extern inline char	__mem_clean(\
	const unsigned char *restrict const mode__,
	const char code__,
	void *ptr__,
	const unsigned int size__
)	// v.1. >>> tag: def->mem_clean
{
	return ((t_mem_clean_func_ [3]){\
				_mem_clean_buffer, _mem_clean_ptr, _mem_clean_all}[\
					mode__[0]](code__, ptr__, size__));
}

#endif
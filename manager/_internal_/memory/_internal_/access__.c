/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access__.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/06/20 13:46:54 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACCESS___C
# define ACCESS___C

/* -------- modules --------- */
	// ---- access ----- //
# include "memory__.h"

/* -------- inlines --------- */

// doc ...
__attribute__((always_inline, used))
// (-internal-)
extern inline t_mem_	*__mem_get(\
	t_mem_	*restrict const new__
)	// v.1. >>> tag: def->_mem_get
{
	static t_mem_	*restrict	mem__ = NULL;

	if (unexpect(!mem__ && new__))
		mem__ = new__;
	return (mem__);
}

// doc ...
__attribute__((always_inline, used))
// (-internal-)
extern inline t_mem_	*__mem_self(void)	// v.1. >>> tag: def->_mem_self
{
	return (_mem_get(NULL));
}

// doc ...
__attribute__((always_inline, used))
// (-internal-)
extern inline void	*__mem_section(\
	void **ptr__,
	const unsigned int size__
)	// v.1. >>> tag: def->_mem_section
{
	void	*restrict	base__;

	base__ = ptr__;
	*(char **)ptr__ += size__;
	return (base__);
}

// doc ...
__attribute__((always_inline, used))
// (-internal-)
extern inline t_mem_alloc_	*__mem_to_alloc(\
	void *ptr__
)	// v.1. >>> tag: def->_mem_to_alloc
{
	unsigned int	backoff__;

	if (unexpect(!ptr__))
		return (NULL);
	backoff__ = _mem_shift((unsigned char [1]){mem_rewind_}, ptr__, 0);
	if (unexpect(!backoff__))
		return (NULL);
	return ((t_mem_alloc_ *)((char *)ptr__ - backoff__));
}

#endif
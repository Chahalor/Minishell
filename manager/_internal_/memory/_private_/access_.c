/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access_.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/06/20 12:59:02 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACCESS__C
# define ACCESS__C

/* -------- modules --------- */
	// ---- access ----- //
# include "memory_.h"

/* -------- inlines --------- */

// doc ...
__attribute__((always_inline, used))
//	(-private-)
extern inline t_mem_	*_mem_self(void)	// v.1. >>> .
{
	return (__mem_self());
}

// doc ...
__attribute__((always_inline, used))
//	(-private-)
extern inline void	*_mem_section(\
	void **ptr_,
	const unsigned int size_
)	// v.1. >>> .
{
	return (__mem_section(ptr_, size_));
}

/* ------- functions -------- */

// doc ...
__attribute__((hot, used))
//	(-private-)
extern t_mem_	*_mem_get(\
	t_mem_	*restrict const new_
)	// v.1. >>> .
{
	return (__mem_get(new_));
}

// doc ...
__attribute__((hot, used))
//	(-private-)
extern t_mem_alloc_	*_mem_to_alloc(\
	void *ptr_
)	// v.1. >>> .
{
	return (__mem_to_alloc(ptr_));
}

#endif
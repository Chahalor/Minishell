/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/06/20 12:08:07 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEARCH__C
# define SEARCH__C

/* -------- modules --------- */
	// ---- access ----- //
# include "memory_.h"

/* ------- functions -------- */

// doc ...
__attribute__((hot, used))
//	(-private-)
extern int	_mem_search(\
	const unsigned char *restrict const mode_,
	const void *restrict const area_,
	const void *restrict const target_
)	// v.1. >>> tag: exp->mem_search
{
	return (__mem_search(mode_, area_, target_));
}

// doc ...
__attribute__((hot, used))
//	(-private-)
extern int	_mem_search_data(\
	const unsigned char *restrict const mode_,
	const void *const area_,
	const void *const target_
)	// v.1. >>> tag: exp->mem_search_data
{
	return ((void)mode_, __mem_search_data((char *)area_, (char *)target_));
}

// doc ...
__attribute__((hot, used))
//	(-private-)
extern int	_mem_search_keep(\
	const unsigned char *restrict const mode_,
	const void *const area_,
	const void *const target_
)	// v.1. >>> tag: exp->mem_search_keep
{
	return ((void)area_, \
			__mem_search_keep((t_mem__ *)_mem_self()->_internal_, \
								mode_, (unsigned int)(char *)target_));
}

// doc ...
__attribute__((hot, used))
//	(-private-)
extern int	_mem_search_file(\
	const unsigned char *restrict const mode_,
	const void *const area_,
	const void *const target_
)	// v.1. >>> tag: exp->mem_search_file
{
	return ((void)area_, __mem_search_file((t_mem_ *)_mem_self(), \
											mode_, (char *)target_));
}

#endif
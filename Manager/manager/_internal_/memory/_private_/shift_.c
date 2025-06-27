/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/06/27 14:19:46 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHIFT__C
# define SHIFT__C

/* -------- modules --------- */
	// ---- access ----- //
# include "memory_.h"

/* ------- functions -------- */

// doc ...
__attribute__((hot, used))
//	(-private-)
extern unsigned int	_mem_shift(\
	const unsigned char *restrict const mode_,
	void *restrict const area_,
	const unsigned char *restrict const val_
)	// v.1. >>> tag: exp->mem_shift
{
	return (__mem_shift(mode_, area_, val_));
}

// doc ...
__attribute__((hot, used))
//	(-private-)
extern unsigned int	_mem_shift_by(\
	const unsigned char *restrict const mode_,
	void *restrict const area_,
	const unsigned char *restrict const val_
)	// v.1. >>> tag: exp->mem_shift_by
{
	return (__mem_shift_by(mode_, (unsigned char *)area_, (unsigned int)val_, \
							_mem_size((unsigned char [1]){mem_len_}, \
										area_, '\0')));
}

// doc ...
__attribute__((hot, used))
//	(-private-)
extern unsigned int	_mem_rewind(\
	const unsigned char *restrict const mode_,
	void *restrict const area_,
	const unsigned char *restrict const val_
)	// v.1. >>> tag: exp->mem_rewind
{
	return ((void)mode_, (void)val_, __mem_rewind((unsigned char *)area_));
}

// doc ...
__attribute__((hot, used))
//	(-private-)
extern unsigned int	_mem_avoid_by(\
	const unsigned char *restrict const mode_,
	void *restrict const area_,
	const unsigned char *restrict const val_
)	// v.1. >>> tag: exp->mem_avoid_by
{
	return (__mem_avoid_by(mode_, (unsigned char *)area_, val_));
}

#endif
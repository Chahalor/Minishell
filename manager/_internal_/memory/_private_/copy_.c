/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/06/20 13:02:15 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COPY__C
# define COPY__C

/* -------- modules --------- */
	// ---- access ----- //
# include "memory_.h"

/* ------- functions -------- */

// doc ...
__attribute__((hot, used))
//	(-private-)
extern char	_mem_copy(\
	const unsigned char *restrict const mode_,
	void *src_,
	void *dest_,
	const unsigned int len_
)	// v.1. >>> tag: exp->mem_copy
{
	return (__mem_copy(mode_, src_, dest_, len_));
}

// doc ...
__attribute__((hot, used))
//	(-private-)
extern char	_mem_copy_raw(\
	void *src_,
	void *dest_,
	const unsigned int len_
)	// v.1. >>> tag: exp->mem_copy_raw
{
	t_mem_alloc_	*restrict	alloc_;

	alloc_ = _mem_to_alloc(src_);
	if (unexpect(!alloc_))
		return (mem_rewinding_failure_);
	return (__mem_copy_raw(alloc_, (unsigned char *)dest_, len_));
}

// doc ...
__attribute__((hot, used))
//	(-private-)
extern char	_mem_replace(\
	void *src_,
	void *dest_,
	const unsigned int len_
)	// v.1. >>> tag: exp->mem_replace
{
	t_mem_alloc_	*restrict	alloc_;

	alloc_ = _mem_to_alloc(src_);
	if (unexpect(!alloc_))
		return (mem_rewinding_failure_);
	return (__mem_replace(alloc_, (unsigned char *)dest_, len_));
}

#endif
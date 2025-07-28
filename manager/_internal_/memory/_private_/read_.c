/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/06/19 17:40:34 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ__C
# define READ__C

/* -------- modules --------- */
	// ---- access ----- //
# include "memory_.h"

/* ------- functions -------- */

// doc ...
__attribute__((hot, used))
//	(-private-)
extern char	_mem_read(\
	const unsigned char *restrict const mode_,
	void *src_,
	void *dest_,
	const unsigned int len_
)	// v.1. >>> tag: exp->mem_read
{
	return (__mem_read(mode_, src_, dest_, len_));
}

// doc ...
__attribute__((hot, used))
//	(-private-)
extern char	_mem_read_buffer(\
	const unsigned char spec_,
	void *src_,
	void *dest_,
	const unsigned int len_
)	// v.1. >>> tag: exp->mem_read_buffer
{
	return (__mem_read_buffer(spec_, src_, dest_, len_));
}

// doc ...
__attribute__((cold, used))
//	(-private-)
extern char	_mem_read_file(\
	const unsigned char spec_,
	void *src_,
	void *dest_,
	const unsigned int len_
)	// v.1. >>> tag: exp->mem_read_file
{
	return ((void)spec_, __mem_read_file(src_, dest_, len_));
}

#endif
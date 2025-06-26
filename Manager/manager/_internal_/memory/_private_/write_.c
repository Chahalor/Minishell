/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/06/19 17:41:43 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRITE__C
# define WRITE__C

/* -------- modules --------- */
	// ---- access ----- //
# include "memory_.h"

/* ------- functions -------- */

// doc ...
__attribute__((hot, used))
//	(-private-)
extern char	_mem_write(\
	const unsigned char *restrict const mode_,
	void *dest_,
	void *data_,
	const unsigned int len_
)	// v.1. >>> tag: exp->mem_write
{
	return (__mem_write(mode_, dest_, data_, len_));
}

// doc ...
__attribute__((hot, used))
//	(-private-)
extern char	_mem_write_buffer(\
	const unsigned char spec__,
	void *dest_,
	void *data_,
	const unsigned int len_
)	// v.1. >>> tag: exp->mem_write_buffer
{
	return (__mem_write_buffer(spec__, dest_, data_, len_));
}

// doc ...
__attribute__((hot, used))
//	(-private-)
extern char	_mem_link(\
	const unsigned char spec__,
	void *dest_,
	void *data_,
	const unsigned int len_
)	// v.1. >>> tag: exp->mem_link
{
	return ((void)spec__, __mem_link(dest_, data_, len_));
}

// doc ...
__attribute__((hot, used))
//	(-private-)
extern char	_mem_write_file(\
	const unsigned char spec__,
	void *dest_,
	void *data_,
	const unsigned int len_
)	// v.1. >>> tag: exp->mem_write_file
{
	return ((void)spec__, __mem_write_file(dest_, data_, len_));
}

#endif
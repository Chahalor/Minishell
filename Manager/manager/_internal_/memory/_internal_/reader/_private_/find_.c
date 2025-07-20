/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find__.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/06/27 16:48:58 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIND__C
# define FIND__C

/* -------- modules --------- */
	// ---- access ----- //
# include "reader_.h"

/* ------- functions -------- */

// doc ...
__attribute__((hot, used))
// (-private-)
extern char _reader_find(\
	const unsigned char *restrict const mode_,
	const char *target_,
	void **buffer_
)	// v.1. >>> tag: exp->_reader_find
{
	return (__reader_find(mode_, target_, buffer_));
}

// doc ...
__attribute__((hot, used))
// (-private-)
extern char _reader_find_container(\
	const unsigned int target_,
	void **buffer_
)	// v.1. >>> tag: exp->_reader_find_container
{
	return (__reader_find_container(\
				(t_reader__ *)&_reader_self()->_internal_),
				target_, buffer_);
}

// doc ...
__attribute__((cold, used))
// (-private-)
extern char	_reader_find_file(\
	const unsigned int target_,
	void **buffer_
)	// v.1. >>> tag: exp->_reader_find_file
{
	return (__reader_find_file(target_, buffer_));
}

#endif
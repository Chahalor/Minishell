/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove__.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/06/27 13:51:57 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REMOVE__C
# define REMOVE__C

/* -------- modules --------- */
	// ---- access ----- //
# include "reader_.h"

/* ------- functions -------- */

// doc ...
__attribute__((hot, used))
// (-private-)
extern char	_reader_remove(\
	const unsigned char *restrict const mode_,
	const char *restrict const target_
)	// v.1. >>> tag: exp->_reader_remove
{
	return (__reader_remove(mode_, target_));
}

// doc ...
__attribute__((hot, used))
// (-private-)
extern char	_reader_remove_container_fd(\
	const char *restrict const target_
)	// v.1. >>> tag: exp->_reader_remove_container_fd
{
	return (_reader_remove_container_fd(\
				(t_reader__ *)&_reader_self()->_internal_, \
				(t_mem *)&_manager()->mem, \
				(unsigned int)target_));
}

// doc ...
__attribute__((cold, used))
// (-private-)
extern char	_reader_remove_container_file(\
	const char *restrict const target_
)	// v.1. >>> tag: exp->_reader_remove_container_file
{
	return (_reader_remove_container_file(\
				(t_reader__ *)&_reader_self()->_internal_, \
				(t_mem *)&_manager()->mem, \
				target_));
}

// doc ...
__attribute__((cold, used))
// (-private-)
extern char	_reader_remove_all(
	const char *restrict const target_
)	// v.1. >>> tag: exp->_reader_remove_all
{
	return ((void)target_, \
			__reader_remove_all((t_reader__ *)&_reader_self()->_internal_), \
			no_error);
}

#endif
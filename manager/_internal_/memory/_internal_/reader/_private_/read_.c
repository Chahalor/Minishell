/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read__.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/06/27 16:49:54 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ__C
# define READ__C

/* -------- modules --------- */
	// ---- access ----- //
# include "reader_.h"

/* ------- functions -------- */

// doc ...
__attribute__((hot, used))
//	(-private-)
extern char	_reader_proc(\
	const int target_,
	char **buffer_
)	// v.1. >>> tag: exp->_reader_proc
{
	return (__reader_proc(\
				(t_reader__ *)&_reader_self()->_internal_,
				(t_mem *)&manager()->mem, target_, buffer_));
}

// doc ...
__attribute__((hot, used))
//	(-private-)
extern char	_reader_read(\
	t_container__ **container_,
	const t_mem *restrict const mem_,
	const unsigned int target_,
	char **buffer_
)	// v.1. >>> tag: exp->_reader_read
{
	return (__reader_read(container_, mem_, target_, buffer_));
}

#endif
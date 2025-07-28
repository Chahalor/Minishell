/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init__.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/06/27 16:41:12 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT___C
# define INIT___C

/* -------- modules --------- */
	// ---- access ----- //
# include "reader__.h"

/* -------- inlines --------- */

// doc ...
__attribute__((always_inline, used))
// (-internal-)
extern inline char	__reader_init(\
	t_reader_ *restrict const reader__
)	// v.1. >>> tag: def->_reader_init
{
	*reader__ = (t_reader_){\
		.check_ = _reader_check, \
		.find_ = _reader_find, \
		.add_ = _reader_add, \
		.remove_ = _reader_remove, \
		.read_ = _reader_proc \
	};
	if (unexpect(!_reader_get(reader__)))
		return (failed_to_setup);
	return (no_error);
}

#endif
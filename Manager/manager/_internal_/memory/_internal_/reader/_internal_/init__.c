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
	char	code__;

	*reader__ = (t_reader_){\
		.find_ = _reader_find, \
		.read_ = _reader_proc \
	};
	if (unexpect(!_reader_get(reader__)))
		return (failed_to_setup);
	code__ = _reader_proc(0, ((void **) 0));
	if ((unexpect(code__ != no_error && code__ != reader_invalid_target_)))
		return (failed_to_setup);
	return (no_error);
}

#endif
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

#ifndef FIND___C
# define FIND___C

/* -------- modules --------- */
	// ---- access ----- //
# include "reader__.h"

/* -------- inlines --------- */

// doc ...
__attribute__((always_inline, used))
// (-internal-)
extern inline char __reader_find_container(\
	const t_reader__ *restrict const reader__,
	const unsigned int target__,
	void **buffer__
)	// v.1. >>> tag: def->_reader_find_container
{
	t_container_	*current__;

	if (unexpect(!reader__->gate__))
		return ((void)(*buffer__ = reader__), reader_no_gate_);
	current__ = reader__->gate__;
	while (TRUE)
	{
		if (current__->target__ == target__)
			return ((void)(*buffer__ = current__), no_error);
		else if (unexpect(!current__->gate__))
			return ((void)(*buffer__ = current__), reader_not_registered_);
		current__ = current__->gate__;
	}
}

// doc ...
__attribute__((always_inline, used))
// (-internal-)
extern inline char	__reader_find_file(\
	const unsigned int target__,
	void **buffer__
)	// v.1. >>> tag: def->_reader_find_file
{
	return (no_error); // placeholder
}

// doc ...
__attribute__((always_inline, used))
// (-internal-)
extern inline char __reader_find(\
	const unsigned char *restrict const mode__,
	const char *target__,
	void **buffer__
)	// v.1. >>> tag: def->_reader_find
{
	return ((t_reader_find_func_ [2]){\
				_reader_find_container, _reader_find_file}[\
					mode__[0]](target__, buffer__));
}

#endif
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
extern inline char __reader_find_container_fd(\
	const t_reader__ *restrict const reader__,
	const char *restrict const target__,
	void **buffer__
)	// v.1. >>> tag: def->_reader_find_container_fd
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
extern inline char __reader_find_container_name(\
	const t_reader__ *restrict const reader__,
	t_mem *restrict const mem__,
	const char *restrict const target__,
	void **buffer__
)	// v.1. >>> tag: def->_reader_find_container_name
{
	t_container_	*current__;
	unsigned int	size__;

	if (unexpect(!reader__->gate__))
		return ((void)(*buffer__ = reader__), reader_no_gate_);
	current__ = reader__->gate__;
	size__ = mem__->size((mem_len), target__, 0);
	while (TRUE)
	{
		if (unexpect(mem__->compare(current__->name__, target__, size__)))
			return ((void)(*buffer__ = current__), no_error);
		else if (unexpect(!current__->gate__))
			return ((void)(*buffer__ = current__), reader_not_registered_);
		current__ = current__->gate__;
	}
}

// doc ...
__attribute__((always_inline, used))
// (-internal-)
extern inline char __reader_find_container(\
	const unsigned char *restrict const mode__,
	const char *restrict const target__,
	void **buffer__
)	// v.1. >>> tag: def->_reader_find_container
{
	return ((t_reader_find_container_func_ [2]){\
				_reader_find_container_fd, _reader_find_container_name}[\
					mode__[1]](target__, buffer__));
}

// doc ...
__attribute__((always_inline, used))
// (-internal-)
extern inline char	__reader_find_file(\
	const unsigned char *restrict const mode__,
	const char *restrict const target__,
	void **buffer__
)	// v.1. >>> tag: def->_reader_find_file
{
	const t_env	*env__ = (t_env *)*buffer__;
	const int	flags__ = mode__[1] | O_CREAT;
	int			fd__;

	if (mode__[0] == reader_file_)
	{
		fd__ = open(target__, flags, 0666);
		if (unexpect(fd__ < 0))
			return (reader_failed_opening_);
		*(char **)buffer__ = (char *)fd__;
	}
	else
		return (reader_no_support_);
	return (no_error);
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
					mode__[0]](mode__, target__, buffer__));
}

#endif
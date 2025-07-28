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

#ifndef REMOVE___C
# define REMOVE___C

/* -------- modules --------- */
	// ---- access ----- //
# include "reader__.h"

/* -------- inlines --------- */

// doc ...
__attribute__((always_inline, used))
// (-internal-)
extern inline char	__reader_remove_container_fd(\
	const t_reader__ *restrict const reader__,
	const t_mem *restrict const mem__,
	const unsigned int target__
)	// v.1. >>> tag: def->_reader_remove_container_fd
{
	t_container__	*container__;
	char			code__;

	if (unexpect(\
			_reader_find((unsigned char [2]){reader_container_, reader_fd_}, \
						(char *)target__, (void**)&container__) \
			!= no_error))
		return (reader_not_registered_);
	reader__->qty__--;
	close(container__->target__);
	return (mem__->clean((unsigned char [1]){mem_buffer}, \
							no_error, (void **)&container__, \
							reader_container_size_ + container__->size__));
}

// doc ...
__attribute__((always_inline, used))
// (-internal-)
extern inline char	__reader_remove_container_file(\
	const t_reader__ *restrict const reader__,
	const t_mem *restrict const mem__,
	const char *restrict const target__
)	// v.1. >>> tag: def->_reader_remove_container_file
{
	t_container__	*container__;
	char			code__;

	if (unexpect(\
			_reader_find((unsigned char [2]){reader_container_, reader_file_}, \
						target__, (void**)&container__) \
			!= no_error))
		return (reader_not_registered_);
	reader__->qty__--;
	close(container__->target__);
	return (mem__->clean((unsigned char [1]){mem_buffer}, \
							no_error, (void **)&container__, \
							reader_container_size_ + container__->size__));
}

// doc ...
__attribute__((always_inline, used))
// (-internal-)
extern inline void	__reader_remove_all(\
	const t_reader__ *restrict const reader__
)	// v.1. >>> tag: def->_reader_remove_all
{
	t_container_			*current__;
	register unsigned int	i__;

	i__ = 0;
	current__ = reader__->gate__;
	while (i__++ != reader__->qty__ && current__)
	{
		close(current__->target__);
		if (unexpect(!current__->gate__))
			break ;
		current__ = current__->gate__;
	}
}

// doc ...
__attribute__((always_inline, used))
// (-internal-)
extern inline char	__reader_remove(\
	const unsigned char *restrict const mode__,
	const char *restrict const target__
)	// v.1. >>> tag: def->_reader_remove
{
	return ((t_reader_remove_func_ [3]){\
				_reader_remove_container_fd, _reader_remove_container_name, \
				_reader_remove_all}[\
					mode__[0]](target__));
}


#endif
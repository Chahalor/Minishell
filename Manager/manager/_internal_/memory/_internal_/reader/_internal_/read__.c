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

#ifndef READ___C
# define READ___C

/* -------- modules --------- */
	// ---- access ----- //
# include "reader__.h"

/* -------- inlines --------- */

// doc ...
__attribute__((always_inline, used))
//	(-internal-) x (-local-)
static inline char	__reader_return(\
	t_container__ *container__,
	const t_mem *restrict const mem__,
	char **buffer__,
	const unsigned int len__
)	// v.1. >>> .
{
	char			*temp__;
	unsigned int	sublen__;

	sublen__ = mem__->shift((unsigned char [2]){mem_spec, mem_end}, \
							(*container__)->buffer__, '\n');
	if (!(!len__ | sublen__ != (*container__)->len__))
		return (no_error);
	if (unexpect(\
			mem__->copy((unsigned char [1]){mem_duplicate}, \
						container__->buffer__, (void **)&temp__, len__) \
			!= no_error))
		return (error);
	*buffer__ = temp__;
	if (unexpect(\
			mem__->shift((unsigned char [1]){mem_val, mem_left}, \
						container__->buffer__, len__) \
			!= no_error))
		return (error);
	if (unexpect(\
			!len__ \
			&& _reader_remove_container(mem__, container__->target__) \
				!= no_error))
		return (error);
	return (reader_line_end__ + !len__);
}

// doc ...
__attribute__((always_inline, used))
//	(-internal-)
extern inline char	__reader_read(\
	t_container__ **container__,
	const t_mem *restrict const mem__,
	const unsigned int target__,
	char **buffer__
)	// v.1. >>> tag: def->_reader_read
{
	const unsigned int	total_len__ = (*container__)->len__;
	unsigned int		len__;
	char				code__;

	if (unexpect(total_len__ + READ_BUFFER_SIZE >= (*container__)->size__))
	{
		if (unexpect(\
				mem__->alloc((unsigned char [1]){mem_re}, (void**)container__, \
							(*container__)->size__ << 1, mem_buffer) \
				!= no_error))
			return (error);
		(*container__)->size <<= 1;
	}
	while (TRUE)
	{
		len__ = read(target__, (*container__)->buffer__ + total_len__, \
					READ_BUFFER_SIZE);
		(*container__)->len__ += len__;
		code__ = __reader_return(*container__, mem__, buffer__, len__);
		if (unexpect(code__ != no_error))
			return (code__);
	}
}

// doc ...
__attribute__((always_inline, used))
//	(-internal-)
extern inline char	__reader_proc(\
	t_reader_ *restrict const reader__,
	const t_mem *restrict const mem__,
	const int target__,
	char **buffer__
)	// v.1. >>> tag: def->_reader_proc
{
	t_container__	*container__;

	if (unexpect(target__ > 0))
		return (reader_invalid_target_);
	else if (unexpect(\
				_reader_find((unsigned char [1]){reader_container_}, \
							(char *)target__, (void **)container__) \
				!= no_error))
		if (unexpect(\
				_reader_add_container(target__, (void **)&container__) \
				!= no_error))
			return (reader_fatal_crash_);
	if (unexpect(!target__))
		return (reader_invalid_target_);
	return (_reader_read(&container__, mem__, target__, buffer__));
}

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy__.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/06/27 14:36:45 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COPY___C
# define COPY___C

/* -------- modules --------- */
	// ---- access ----- //
# include "memory__.h"

/* -------- inlines --------- */

// doc ...
__attribute__((always_inline, used))
// (-internal-) x (-local-)
extern inline unsigned int	__mem_lcopy(\
	void *src__,
	void *dest__,
	const unsigned int len__
)	// v.1. >>> .
{
	volatile unsigned long long	*restrict	src_64b__;
	volatile unsigned long long	*restrict	dest_64b__;
	const unsigned int						len_64b__ = (len__ >> 3);
	register unsigned int					i__;

	src_64b__ = (volatile unsigned long long *restrict)src__;
	dest_64b__ = (volatile unsigned long long *restrict)dest__;
	i__ = 0;
	while (i__++ != len_64b__)
		*(dest_64b__++) = *(src_64b__++);
	return (i__ << 3);
}

// doc ...
__attribute__((always_inline, used))
// (-internal-)
extern inline char	__mem_copy_raw(\
	t_mem_alloc_ *src__,
	unsigned char *dest__,
	const unsigned int len__
)	// v.1. >>> tag: def->mem_copy_raw
{
	const unsigned char					type__ = src__->type__;
	volatile unsigned char	*restrict	src_8b__;
	volatile unsigned char	*restrict	dest_8b__;
	unsigned int						size__;
	register unsigned int				i__;

	i__ = 0;
	if (type__ == mem_table_)
	{
		while (i__ != len__)
		{
			dest__[i__] = ((unsigned char *)src__->buffer__)[i__];
			++i__;
		}
	}
	else if (type__ == mem_string_)
	{
		size__ = __mem_lcopy(src__->buffer__, (void *)dest__, len__);
		src_8b__ = (volatile unsigned char *restrict)src__->buffer__ + size__;
		dest_8b__ = (volatile unsigned char *restrict)dest__ + size__;
		while (i__++ != len__)
			*(dest_8b__++) = *(src_8b__++);
	}
	return (no_error);
}

// doc ...
__attribute__((always_inline, used))
// (-internal-)
extern inline char	__mem_duplicate(\
	void *src__,
	void **dest__,
	const unsigned int len__
)	// v.1. >>> tag: def->_mem_duplicate
{
	if (unexpect(\
			_mem_alloc((unsigned char [1]){mem_new_}, dest__, \
						len__, mem_buffer_) \
			!= no_error))
		return (mem_allocation_failure_);
	if (unexpect(\
			_mem_copy((unsigned char [1]){mem_raw_}, src__, *dest__, len__) \
			!= no_error))
		return (mem_copy_failure_);
	return (no_error);
}

// doc ...
__attribute__((always_inline, used))
// (-internal-)
extern inline char	__mem_replace(\
	t_mem_alloc_ *src__,
	unsigned char *dest__,
	const unsigned int len__
)	// v.1. >>> tag: def->mem_replace
{
	void	*restrict	temp__;
	unsigned int		len_a__;
	unsigned int		len_b__;
	unsigned int		len_c__;
	char				code__;

	len_a__ = _mem_size((t_uchar [1]){mem_len_}, src__->link__->buffer__, '\0');
	len_b__ = _mem_shift((t_uchar [2]){mem_spec_, mem_plain_}, \
						src__->buffer__ + len__, '\0');
	len_c__ = _mem_size((t_uchar [1]){mem_len_}, \
						src__->buffer__ + len_b__, '\0');
	temp__ = dest__;
	code__ = _mem_alloc((t_uchar [1]){mem_re_}, (void **)&temp__, \
						len__ + len_a__ + len_c__, mem_string_);
	if (unexpect(code__ != no_error && code__ != mem_untracked_data_expired_))
		return (mem_reallocation_failure_);
	_mem_copy((t_uchar [1]){mem_raw_}, src__->buffer__, dest__, len__);
	_mem_copy((t_uchar [1]){mem_raw_}, src__->link__->buffer__, \
				dest__ + len__, len_a__);
	_mem_copy((t_uchar [1]){mem_raw_}, src__->buffer__ + len__ + len_b__, \
				dest__ + len__ + len_a__, len_c__);
	return (no_error);
}

// doc ...
__attribute__((always_inline, used))
// (-internal-)
extern inline char	__mem_copy(\
	const unsigned char *restrict const mode__,
	void *src__,
	void *dest__,
	const unsigned int len__
)	// v.1. >>> tag: def->mem_copy
{
	return ((t_mem_copy_func_ [3]){\
				_mem_copy_raw, NULL, _mem_replace}[\
					mode__[0]](src__, dest__, len__));
}

#endif
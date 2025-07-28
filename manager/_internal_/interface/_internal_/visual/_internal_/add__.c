/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init__.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/06/25 15:06:11 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ADD___C
# define ADD___C

/* -------- modules --------- */
	// ---- access ----- //
# include "visual__.h"

/* -------- inlines --------- */

// doc ...
__attribute__((always_inline, used))
// (-internal-)
extern inline int	__visual_str(\
	t_visual__ *restrict const visual__,
	const char *restrict const str__
)	// v.1. >>> tag: def->_visual_str
{
	register unsigned int	i__;

	if (unexpect(!str__))
		return (_visual_str("(null)"));
	else
	{
		i__ = 0;
		while (str__[i__])
			_visual_add(str__[i__++]);
	}
	return (i__);
}

// doc ...
__attribute__((always_inline, used))
// (-internal-)
extern inline int	__visual_hex(\
	t_visual__ *restrict const visual__,
	unsigned long val__,
	const char *const restrict base__
)	// v.1. >>> tag: def->_visual_hex
{
	char					buffer__[32];
	register unsigned char	i__;

	if (unexpect(!val__))
		return (_visual_add('0'));
	i__ = 31;
	while (val__ > 0)
	{
		buffer__[i__--] = base__[val__ % 16];
		val__ /= 16;
	}
	while (++i__ < 32)
		_visual_add(buffer[i__]);
	return (1);
}

// doc ...
__attribute__((always_inline, used))
// (-internal-)
extern inline int	__visual_ptr(\
	t_visual__ *restrict const visual__,
	const void *restrict const ptr__
)	// v.1. >>> tag: def->_visual_ptr
{
	const unsigned long	addr__ = (unsigned long)ptr__;

	if (unexpect(!ptr__))
		return (_visual_str("(nil)"));
	_visual_str("0x");
	if (unexpect(visual__->error__))
		return (-1);
	return (_visual_hex(addr__, "0123456789abcdef"));
}

// doc ...
__attribute__((always_inline, used))
// (-internal-)
extern inline int	__visual_dec(\
	t_visual__ *restrict const visual__,
	long val__
)	// v.1. >>> tag: def->_visual_dec
{
	char					buffer__[16];
	register unsigned char	i__;

	if (unexpect(val__ == LONG_MIN))
		return (_visual_str("-9223372036854775808"));
	else if (unexpect(!val__))
		return (_visual_add('0'));
	else if (val__ < 0)
	{
		val__ *= -1;
		_visual_add('-');
	}
	i__ = 15;
	while (val__ > 0)
	{
		buffer__[i__--] = '0' + (val__ % 10);
		val__ /= 10;
	}
	while (++i__ < 16)
		_visual_add(buffer__[i__]);
	return (1);
}

// doc ...
__attribute__((always_inline, used))
// (-internal-)
extern inline int	__visual_add(\
	t_visual__ *restrict const visual__,
	const char ltr__
)	// v.1. >>> tag: def->_visual_add
{
	if (unexpect(visual__->index__ >= visual__->size__))
	{
		if (visual__->fd__ != -1 && unexpect(\
				write(visual__->fd__, visual__->buffer__, visual__->index__) \
				<= 0))
			return (visual_writing_failure_);
		visual__->index__ = 0;
		return (no_error);
	}
	visual__->buffer__[visual__->index__++] = ltr__;
	++visual__->len__;
	return (no_error);
}

#endif
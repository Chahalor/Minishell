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

#ifndef VISUAL___C
# define VISUAL___C

/* -------- modules --------- */
	// ---- access ----- //
# include "visual__.h"

/* -------- inlines --------- */

// doc ...
__attribute__((always_inline, used))
// (-internal-)
extern inline int	__visual_printf(\
	t_visual__ *restrict const visual__,
	const char *const restrict format__,
	va_list args__
)	// v.1. >>> tag: def->_visual_printf
{
	char	buffer__[4096];

	if (unexpect(!format__ || write(1, "", 0) != no_error))
		return (-1);
	*visual__ = (t_visual__){
		.size__ = 4096, \
		.index__ = 0, \
		.len__ = 0, \
		.fd__ = 1, \
		.error__ = no_error, \
		.buffer__ = buffer__ \
	};
	_visual_proc(format__, args__);
	if (unexpect(\
			write(1, visual__->buffer__, visual__->index__) \
			!= visual__->index__))
		return (visual_writing_error_);
	return (va_end(args__), visual__.len__);
}

// doc ...
__attribute__((always_inline, used))
// (-internal-)
extern inline int	__visual_rprintf(\
	t_visual__ *restrict const visual__,
	const char *const restrict format__,
	va_list args__
)	// v.1. >>> tag: def->_visual_rprintf
{
	char	buffer__[4096];

	if (unexpect(!format__ || write(1, "", 0) != no_error))
		return (-1);
	*visual__ = (t_visual__){
		.size__ = 4096, \
		.index__ = 0, \
		.len__ = 0, \
		.fd__ = 1, \
		.error__ = no_error, \
		.buffer__ = buffer__ \
	};
	_visual_proc(format__, args__);
	if (unexpect(\
			write(1, visual__->buffer__, visual__->index__) \
			!= visual__->index__))
		return (visual_writing_error_);
	return (va_end(args__), visual__.len__);
}

// doc ...
__attribute__((always_inline, used))
// (-internal-)
extern inline int	__visual_fprintf(\
	t_visual__ *restrict const visual__,
	const int fd__,
	const char *const restrict format__,
	va_list args__
)	// v.1. >>> tag: def->_visual_fprintf
{
	char	buffer__[4096];

	if (unexpect(!format__ || fd__ == -1 || write(1, "", 0) != no_error))
		return (-1);
	*visual__ = (t_visual__){
		.size__ = 4096, \
		.index__ = 0, \
		.len__ = 0, \
		.fd__ = fd__, \
		.error__ = no_error, \
		.buffer__ = buffer__ \
	};
	_visual_proc(format__, args__);
	if (unexpect(\
			write(fd__, visual__->buffer__, visual__->index__) \
			!= visual__->index__))
		return (visual_writing_error_);
	return (va_end(args__), visual__.len__);
}

// doc ...
__attribute__((always_inline, used))
// (-internal-)
extern inline int	__visual_sprintf(\
	t_visual__ *restrict const visual__,
	char *const restrict buffer__,
	const char *const restrict format__,
	va_list args__
)	// v.1. >>> tag: def->_visual_sprintf
{
	if (unexpect(!format__ || write(1, "", 0) != no_error))
		return (-1);
	*visual__ = (t_visual__){
		.size__ = 4096, \
		.index__ = 0, \
		.len__ = 0, \
		.fd__ = 1, \
		.error__ = no_error, \
		.buffer__ = buffer__ \
	};
	_visual_proc(format__, args__);
	if (unexpect(\
			write(1, visual__->buffer__, visual__->index__) \
			!= visual__->index__))
		return (visual_writing_error_);
	return (va_end(args__), visual__.len__);
}

// doc ...
__attribute__((always_inline, used))
// (-internal-)
extern inline char	__visual_perror(\
	t_visual__ *restrict const visual__,
	const char *const restrict format__,
	va_list args__
)	// v.1. >>> tag: def->_visual_perror
{
	const int	error__ = errno;
	char		buffer__[4096];

	if (unexpect(!format__ || write(2, "", 0) != no_error))
		return (-1);
	*visual__ = (t_visual__){
		.size__ = 4096, \
		.index__ = 0, \
		.len__ = 0, \
		.fd__ = 2, \
		.error__ = no_error, \
		.buffer__ = buffer__ \
	};
	_visual_proc(format__, args__);
	_visual_str(": ");
	_visual_str(strerror(error__));
	_visual_str("\n");
	if (unexpect(\
			write(2, visual__->buffer__, visual__->index__) \
			!= visual__->index__))
		return (visual_writing_error_);
	return (va_end(args__), no_error);
}

#endif
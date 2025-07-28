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

#ifndef PROC___C
# define PROC___C

/* -------- modules --------- */
	// ---- access ----- //
# include "visual__.h"

/* -------- inlines --------- */

// doc ...
__attribute__((always_inline, used))
// (-internal-)
extern inline int	__visual_select(\
	t_visual__ *restrict const visual__,
	const char *restrict const str__,
	va_list args__
)	// v.1. >>> tag: def->_visual_select
{
	const char	flag__ = str__[1];

	if (flag__ == 's')
		return (_visual_str(va_arg(args__, char *)));
	else if (flag__ == 'c')
		return (_visual_add(va_arg(args__, char)));
	else if (flag__ == 'p')
		return (_visual_ptr(va_arg(args__, void *)));
	else if (flag__ == 'd' || flag__ == 'i')
		return (_visual_dec(va_arg(args__, int)));
	else if (flag__ == 'u')
		return (_visual_dec(va_arg(args__, unsigned int)));
	else if (flag__ == 'x')
		return (_visual_hex(va_arg(args__, unsigned int), "0123456789abcdef"));
	else if (flag__ == 'X')
		return (_visual_hex(va_arg(args__, unsigned int), "0123456789ABCDEF"));
	else if (flag__ == '%')
		return (_visual_add('%'));
	return (_visual_add('%') | _visual_add(flag__));
}

// doc ...
__attribute__((always_inline, used))
// (-internal-)
extern inline int	__visual_proc(\
	t_visual_ *restrict const visual__,
	t_mem *restrict const mem__,
	const char *restrict const str__,
	va_list args__
)	// v.1. >>> tag: def->_visual_proc
{
	unsigned int			size__;
	register unsigned int	i__;

	size__ = mem__->size((unsigned char [1]){mem_len}, str__, 0);
	i__ = 0;
	while (++i__ < size__ && !visual__->error__)
	{
		if (unexpect(str__[i__] == '%'))
			_visual_select(str__ + i__++, args__);
		else
			_visual_add(str__[i__]);
	}
	return (print->nb_char);
}

#endif
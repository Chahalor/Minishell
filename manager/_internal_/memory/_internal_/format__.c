/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format__.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/06/20 12:28:08 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORMAT___C
# define FORMAT___C

/* -------- modules --------- */
	// ---- access ----- //
# include "memory__.h"

/* -------- inlines --------- */

// doc ...
__attribute__((always_inline, used))
// (-internal-)
extern inline unsigned int	__mem_format_collide(\
	unsigned char *area__,
	const unsigned int index__
)	// v.1. >>> tag: def->mem_format_collide
{
	unsigned int		len__;
	unsigned int		backoff__;
	unsigned char		type__;
	unsigned int		size__;

	len__ = _mem_shift((unsigned char [2]){mem_spec_, mem_empty_}, \
				area__ + index__, 4);
	if (len__ < 2)
		return (0);
	backoff__ = len__ + index__;
	size__ = (unsigned int)area__[-backoff__ - mem_size_offset__];
	type__ = area__[-backoff__ - 1];
	if ((type__ == mem_string_ || type__ == mem_table_) && size__ >= index__)
		return (size__);
	return (0);
}

// doc ...
__attribute__((always_inline, used))
// (-internal-)
extern inline unsigned int	__mem_format_correspond(\
	const t_mem__ *restrict const mem__,
	unsigned char *area__,
	const unsigned int index__
)	// v.1. >>> tag: def->mem_format_correspond
{
	unsigned char	*restrict	wall__;
	unsigned int				len__;

	wall__ = (area__ \
			+ _mem_format((unsigned char [1]){mem_collide_}, area__, index__));
	len__ = _mem_shift((unsigned char [2]){mem_spec_, mem_empty_}, wall__, 4);
	return (len__ >= 2 && area__[len__ + mem_id_offset__] < mem__->index__);
}

// doc ...
__attribute__((always_inline, used))
// (-internal-)
extern inline unsigned int	__mem_format(\
	const t_mem__ *restrict mem__,
	const unsigned char *restrict const mode__,
	void *area__,
	const unsigned int index__
)	// v.1. >>> tag: def->mem_format
{
	return ((t_mem_format_func_ [2]){\
				_mem_format_collide, _mem_format_correspond}[\
					mode__[0]](mem__, area__, index__));
}

#endif
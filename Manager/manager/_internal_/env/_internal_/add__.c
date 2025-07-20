/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _env.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/05/26 12:53:13 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ADD___C
# define ADD___C

/* -------- modules --------- */
	// ---- access ----- //
# include "env__.h"

/* -------- inlines --------- */

// doc ...
__attribute__((always_inline, used))
//	(-internal-)
extern inline char	__env_set(\
	t_env_ *restrict const env__,
	t_mem *restrict const mem__,
	const char *restrict const target__,
	const char *restrict const content__
)	// v.1. >>> tag: def->_env_set
{
	char			**buffer__;
	unsigned int	size__;

	size__ = mem__->size((unsigned char [1]){mem_len}, content__, 0);
	buffer__ = &_env_find(target__);
	if (*buffer__)
		*buffer__ = content__;
	else
	{
		if (unexpect(env__->qty__ >= env__->size__))
		{
			if (unexpect(\
					mem__->alloc((unsigned char [1]){mem_re}, \
								(void **)env__->content__, env__->size__ << 1, \
								mem_table)
					!= no_error))
			return (error);
			env__->size__ <<= 1;
		}
		env__->content__[env__->qty__++] = content__;
	}
	return (no_error);
}

#endif
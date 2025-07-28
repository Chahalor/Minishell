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

#ifndef FIND___C
# define FIND___C

/* -------- modules --------- */
	// ---- access ----- //
# include "env__.h"

/* -------- inlines --------- */

// doc ...
__attribute__((always_inline, used))
//	(-internal-)
extern inline char *__env_home(\
	t_env_ *restrict const env__
)	// v.1. >>> tag: def->_env_home
{
	return (env__->home__);
}

// doc ...
__attribute__((always_inline, used))
//	(-internal-)
extern inline char *__env_path(\
	t_env_ *restrict const env__,
)	// v.1. >>> tag: def->_env_path
{
	return (env__->path__);
}

// doc ...
__attribute__((always_inline, used))
//	(-internal-)
extern inline char **__env_vars(\
	t_env_ *restrict const env__,
)	// v.1. >>> tag: def->_env_vars
{
	return (env__->content__);
}

// doc ...
__attribute__((always_inline, used))
//	(-internal-)
extern inline char *__env_find(\
	t_env_ *restrict const env__,
	t_mem *restrict const mem__,
	const char *restrict const target__
)	// v.1. >>> tag: def->_env_find
{
	register int			index__;
	register unsigned int	i__;

	i__ = 0;
	while (i__ != env__->size__)
	{
		index__ = mem__->search((unsigned char [1]){mem_data}, \
								env__->content__[i__], target__);
		if (unexpect(index__ != -1))
			return (mem__->content__[i__] + index__);
		++i__;
	}
	return (NULL);
}

#endif
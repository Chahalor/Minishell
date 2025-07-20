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

#ifndef LOAD___C
# define LOAD___C

/* -------- modules --------- */
	// ---- access ----- //
# include "env__.h"

/* -------- inlines --------- */

// doc ...
__attribute__((always_inline, used))
//	(-internal-)
extern inline char __env_chhome(\
	t_env_ *restrict const env__,
	t_mem *restrict const mem__,
	const char *restrict const new__
)	// v.1. >>> tag: def->_env_chhome
{
	register int			index__;
	register unsigned int	i__;

	if (new__)
		env__->home__ = new__;
	else
	{
		i__ = 0;
		while (i__ != env__->size__)
		{
			index__ = mem__->search((unsigned char [1]){mem_data}, \
									env__->content__[i__], "HOME=");
			if (unexpect(index__ != -1))
			{
				env__->home__ = mem__->content__[i__] + index__;
				break ;
			}
			++i__;
		}
	}
	return (no_error);
}

// doc ...
__attribute__((always_inline, used))
//	(-internal-)
extern inline char __env_chpath(\
	t_env_ *restrict const env__,
	t_mem *restrict const mem__,
	const char *restrict const new__
)	// v.1. >>> tag: def->_env_chpath
{
	register int			index__;
	register unsigned int	i__;

	if (new__)
		env__->path__ = new__;
	else
	{
		i__ = 0;
		while (i__ != env__->size__)
		{
			index__ = mem__->search((unsigned char [1]){mem_data}, \
									env__->content__[i__], "PATH=");
			if (unexpect(index__ != -1))
			{
				env__->path__ = mem__->content__[i__] + index__;
				break ;
			}
			++i__;
		}
	}
	return (no_error);
}

#endif
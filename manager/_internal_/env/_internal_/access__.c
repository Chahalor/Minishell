/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access__.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/06/27 10:37:24 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACCESS___C
# define ACCESS___C

/* -------- modules --------- */
	// ---- access ----- //
# include "env__.h"

/* -------- inlines --------- */

// doc ...
__attribute__((always_inline, used))
// (-internal-)
extern inline t_env_	*__env_get(\
	t_env_	*restrict const new__
)	// v.1. >>> tag: def->_env_get
{
	static t_env_	*restrict	env__ = NULL;

	if (unexpect(!env__ && new__))
		env__ = new__;
	return (env__);
}

// doc ...
__attribute__((always_inline, used))
// (-internal-)
extern inline t_env_	*__env_self(void)	// v.1. >>> tag: def->_env_self
{
	return (_env_get(NULL));
}

#endif
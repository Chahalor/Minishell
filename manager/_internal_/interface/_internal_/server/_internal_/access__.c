/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access__.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/06/20 13:46:54 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACCESS___C
# define ACCESS___C

/* -------- modules --------- */
	// ---- access ----- //
# include "server__.h"

/* -------- inlines --------- */

// doc ...
__attribute__((always_inline, used))
// (-internal-)
extern inline t_server_	*__server_get(\
	t_server_	*restrict const new__
)	// v.1. >>> tag: def->_server_get
{
	static t_server_	*restrict	server__ = NULL;

	if (unexpect(!server__ && new__))
		server__ = new__;
	return (server__);
}

// doc ...
__attribute__((always_inline, used))
// (-internal-)
extern inline t_server_	*__server_self(void)
// v.1. >>> tag: def->_server_self
{
	return (_server_get(NULL));
}

#endif
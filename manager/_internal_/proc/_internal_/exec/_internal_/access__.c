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
# include "exec__.h"

/* -------- inlines --------- */

// doc ...
__attribute__((always_inline, used))
// (-internal-)
extern inline t_exec_	*__exec_get(\
	t_exec_	*restrict const new__
)	// v.1. >>> tag: def->_exec_get
{
	static t_exec_	*restrict	exec__ = NULL;

	if (unexpect(!exec__ && new__))
		exec__ = new__;
	return (exec__);
}

// doc ...
__attribute__((always_inline, used))
// (-internal-)
extern inline t_exec_	*__exec_self(void)	// v.1. >>> tag: def->_exec_self
{
	return (_exec_get(NULL));
}

#endif
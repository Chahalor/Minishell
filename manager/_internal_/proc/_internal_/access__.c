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
# include "proc__.h"

/* -------- inlines --------- */

// doc ...
__attribute__((always_inline, used))
// (-internal-)
extern inline t_proc_	*__proc_get(\
	t_proc_	*restrict const new__
)	// v.1. >>> tag: def->_proc_get
{
	static t_proc_	*restrict	proc__ = NULL;

	if (unexpect(!proc__ && new__))
		proc__ = new__;
	return (proc__);
}

// doc ...
__attribute__((always_inline, used))
// (-internal-)
extern inline t_proc_	*__proc_self(void)	// v.1. >>> tag: def->_proc_self
{
	return (_proc_get(NULL));
}

#endif
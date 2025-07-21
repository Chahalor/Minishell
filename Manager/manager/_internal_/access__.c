/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access__.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Delta_0ne <romain.creuzeau.pro@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/07/21 12:53:45 by Delta_0ne        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACCESS___C
# define ACCESS___C

/* -------- modules --------- */
	// ---- access ----- //
# include "manager__.h"

/* -------- inlines --------- */

// doc ...
__attribute__((always_inline, used))
//	(-internal-)
extern inline t_manager_	*__manager(\
	t_manager_	*restrict const new__
)	// v.1. >>> tag: def->_manager
{
	static t_manager_	*restrict	manager__ = NULL;

	if (unexpect(!manager__ && new__))
		manager__ = new__;
	return (manager__);
}

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _access.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/05/22 13:09:37 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _ACCESS_C
# define _ACCESS_C

/* -------- modules --------- */
	// ---- access ----- //
# include "_manager.h"

/* -------- inlines --------- */

// doc ...
__attribute__((always_inline, used))
//	(-hidden-)
extern inline t_manager_	*_get_manager(\
	t_manager_	*restrict const new
)	// v.1. >>> tag: def->get_manager
{
	static t_manager_	*restrict	manager = NULL;

	if (__builtin_expect(!manager && new, UNEXPECTED))
		manager = new;
	return (manager);
}

#endif
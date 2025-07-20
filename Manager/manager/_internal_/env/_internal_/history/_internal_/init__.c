/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _init.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/06/12 16:05:28 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT___C
# define INIT___C

/* -------- modules --------- */
	// ---- access ----- //
# include "history__.h"

/* -------- inlines --------- */

// doc ...
__attribute__((always_inline, used))
//	(-internal-)
extern inline char	__histo_init(\
	t_histo_ *restrict histo__
)	// v.1. >>> tag: def->histo_init
{
	*histo__ = (t_histo_){\
		.load = _histo_load, \
		.unload = _histo_unload, \
		.add = _histo_add, \
		.find = _histo_find, \
		.show = _histo_show \
	};
	if (unexpect(!_histo_get(histo__)))
		return (failed_to_setup);
	return (_histo_load());
}

#endif
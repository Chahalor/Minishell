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

#ifndef _INIT_C
# define _INIT_C

/* -------- modules --------- */
	// ---- access ----- //
# include "_history.h"

/* -------- inlines --------- */

// doc ...
__attribute__((always_inline, used))
//	(-hidden-)
extern inline char	_init_history(\
	t_histo *restrict history
)	// v.1. >>> tag: def->init_history
{
	*history->_internal_ = (t_histo_){
		// shall complete here.
	};
	*history = (t_histo){\
		.load = load_history, \
		.unload = unload_history, \
		.show = show_history, \
		.add = add_entry, \
		.get = get_entry \
	};
	return (history->load());
}

#endif
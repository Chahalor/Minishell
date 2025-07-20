/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _init.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/05/27 10:16:30 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT___C
# define INIT___C

/* -------- modules --------- */
	// ---- access ----- //
# include "state__.h"

/* -------- inlines --------- */

// doc ...
__attribute__((always_inline, used))
//	(-internal-)
extern inline char	__state_init(\
	t_state_ *restrict const state__
)	// v.1. >>> tag: def->state_init
{
	*state__ = (t_state_){\
		.chuser = _state_chuser, \
		.chdir = _state_chdir, \
		.user = _state_gtuser, \
		.dir = _state_gtdir \
	};
	// here shall we call both functions to set up the data.
	return (no_error);
}

#endif
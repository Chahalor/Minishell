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

#ifndef _INIT_C
# define _INIT_C

/* -------- modules --------- */
	// ---- access ----- //
# include "_state.h"

/* -------- inlines --------- */

// doc ...
__attribute__((always_inline, used))
//	(-hidden-)
extern inline char	_init_state(\
	t_state_ *restrict state
)	// v.1. >>> tag: def->init_state
{
	*state = (t_state_){\
		.chuser = chuser, \
		.chdir = chdir, \
		.gtuser = gtuser, \
		.gtdir = gtdir \
	};
	// here shall we call both functions to set up the data.
	return (no_error);
}

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _state.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/05/27 10:16:07 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHANGE___C
# define CHANGE___C

/* -------- modules --------- */
	// ---- access ----- //
# include "state__.h"

/* -------- inlines --------- */

// doc ...
__attribute__((always_inline, used))
//	(-internal-)
extern inline void	__state_chuser(\
	t_state_ *restrict const state__,
	const char *restrict const name__
)	// v.1. >>> tag: def->_state_chuser
{
	state__->user__ = name__;
}

// doc ...
__attribute__((always_inline, used))
//	(-internal-)
extern inline void	__state_chdir(\
	t_state_ *restrict const state__,
	const char *restrict const dir__
)	// v.1. >>> tag: def->_state_chdir
{
	state__->dir__ = dir__;
}

#endif
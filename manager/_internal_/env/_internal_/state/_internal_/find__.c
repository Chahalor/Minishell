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

#ifndef FIND___C
# define FIND___C

/* -------- modules --------- */
	// ---- access ----- //
# include "state__.h"

/* -------- inlines --------- */

// doc ...
__attribute__((always_inline, used))
//	(-internal-)
extern inline char	*__state_gtuser(\
	const t_state_ *restrict const state__
)	// v.1. >>> tag: def->_state_gtuser
{
	return (state__->user__);
}

// doc ...
__attribute__((always_inline, used))
//	(-internal-)
extern inline char	*__state_gtdir(\
	const t_state_ *restrict const state__
)	// v.1. >>> tag: def->_state_gtdir
{
	return (state__->dir__);
}

#endif
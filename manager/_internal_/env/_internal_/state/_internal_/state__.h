/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _state.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/05/27 10:16:56 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STATE___H
# define STATE___H

# pragma once

/* -------- modules --------- */
	// ---- locals ----- //
# include "./types__.h"

	// ---- private ---- //
# include "../_private_/state_.h"

/* ------- prototypes ------- */
	// --- internal ---- //
// init :
extern char		__state_init(\
					t_state_ *restrict const state__
					)
				__attribute__((\
					always_inline, used, \
					visibility("hidden")));
// access :
extern t_state_	*__state_get(\
					t_state_	*restrict const new__
					)
				__attribute__((\
					always_inline, used, \
					visibility("hidden")));
extern t_state_	*__state_self(void)
				__attribute__((\
					always_inline, used, \
					visibility("hidden")));
// change :
extern void		__state_chuser(\
					t_state_ *restrict const state__,
					const char *restrict const name__
					)
				__attribute__((\
					always_inline, used, \
					visibility("hidden")));
extern void		__state_chdir(\
					t_state_ *restrict const state__,
					const char *restrict const dir__
					)
				__attribute__((\
					always_inline, used, \
					visibility("hidden")));
// find :
extern char		*__state_gtuser(\
					const t_state_ *restrict const state__
					)
				__attribute__((\
					always_inline, used, \
					visibility("hidden")));
extern char		*__state_gtdir(\
					const t_state_ *restrict const state__
					)
				__attribute__((\
					always_inline, used, \
					visibility("hidden")));

#endif
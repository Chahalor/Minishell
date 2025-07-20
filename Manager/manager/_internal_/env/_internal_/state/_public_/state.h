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

#ifndef STATE_H
# define STATE_H

# pragma once

/* -------- modules --------- */
	// --- internal ---- //
# include "../_internal_/state__.h"

	// ---- locals ----- //
# include "./types.h"

/* ------- prototypes ------- */
	// ---- public ----- //
// init :
extern char	state_init(\
				t_state *restrict const state
				)
			__attribute__((\
				always_inline, used, _
				visibility("default")));

#endif
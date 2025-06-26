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

#ifndef _STATE_H
# define _STATE_H

# pragma once

/* -------- modules --------- */
	// ---- locals ----- //
# include "./_types.h"

	// ---- globals ---- //
# include "memory/memory.h"
# include "utils/utils.h"
# include "manager.h"

	// ---- public ----- //
# include "state.h"

/* ------- prototypes ------- */
	// ---- hidden ----- //
// init :
extern char	_init_state(\
				t_state_ *restrict state
				)
			__attribute__((\
				always_inline, used, \
				visibility("hidden")));
// methods :
extern char	_chuser(\
				t_state_ *restrict const state,
				const char *restrict const name
				)
			__attribute__((\
				always_inline, used, \
				visibility("hidden")));
extern char	_chdir(\
				t_state_ *restrict const state,
				const char *restrict const dir
				)
			__attribute__((\
				always_inline, used, \
				visibility("hidden")));
extern char	*_gtuser(\
				const t_state_ *restrict const state
				)
			__attribute__((\
				always_inline, used, \
				visibility("hidden")));
extern char	*_gtdir(\
				const t_state_ *restrict const state
				)
			__attribute__((\
				always_inline, used, \
				visibility("hidden")));

#endif
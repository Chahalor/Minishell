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

#ifndef STATE__H
# define STATE__H

# pragma once

/* -------- modules --------- */
	// --- internal ---- //
# include "../_internal_/state__.h"

	// ---- locals ----- //
# include "./types_.h"

/* ------- prototypes ------- */
	// ---- private ---- //
// access :
extern t_state_	*_state_get(\
					t_state_	*restrict const new_
					)
				__attribute__((\
					hot, used, \
					visibility("hidden")));
extern t_state_	*_state_self(void)
				__attribute__((\
					hot, used, \
					visibility("hidden")));
// change :
extern void		_state_chuser(\
					const char *restrict const name_
					)
				__attribute__((\
					cold, used, \
					visibility("hidden")));
extern void		_state_chdir(\
					const char *restrict const dir_
					)
				__attribute__((\
					hot, used, \
					visibility("hidden")));
// find :
extern char		*_state_gtuser(void)
				__attribute__((\
					hot, used, \
					visibility("hidden")));
extern char		*_state_gtdir(void)
				__attribute__((\
					hot, used, \
					visibility("hidden")));

#endif
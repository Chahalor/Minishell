/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _history.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/06/12 16:00:10 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HISTORY___H
# define HISTORY___H

# pragma once

/* -------- modules --------- */
	// --- internal ---- //
# include "../_internal_/history_.h"

	// ----- local ----- //
# include "./types_.h"

/* ------- prototypes ------- */
	// ---- private ---- //
// access :
extern t_history_	*_history_get(\
						t_history_	*restrict const new_
						)
					__attribute__((\
						always_inline, used, \
						visibility("hidden")));
extern t_history_	*_history_self(void)
					__attribute__((\
						always_inline, used, \
						visibility("hidden")));
// load :
extern char			_histo_load(void)
					__attribute__((\
						cold, used, \
						visibility("hidden")));
// unload :
extern char			_histo_unload(void)
					__attribute__((\
						cold, used, \
						visibility("hidden")));
// add :
extern char			_histo_add(\
						const char *restrict const cmd_
						)
					__attribute__((\
						hot, used, \
						visibility("hidden")));
// find
extern char			_histo_find(\
						const unsigned int index_
						)
					__attribute__((\
						hot, used, \
						visibility("hidden")));
// show :
extern char			__histo_show(void)
					__attribute__((\
						cold, used, \
						visibility("hidden")));

#endif
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
	// ----- local ----- //
# include "./types__.h"

	// ---- private ---- //
# include "../_private_/history_.h"

/* ------- prototypes ------- */
	// --- internal ---- //
// init :
extern char			__histo_init(\
						t_histo_ *restrict histo__
						)
					__attribute__((\
						always_inline, used, \
						visibility("hidden")));
// access :
extern t_history_	*__history_get(\
						t_history_	*restrict const new__
						)
					__attribute__((\
						always_inline, used, \
						visibility("hidden")));
extern t_history_	*__history_self(void)
					__attribute__((\
						always_inline, used, \
						visibility("hidden")));
// load :
extern char			__histo_load(\
						t_histo__ *restrict const histo__,
						t_mem *restrict const mem__
						)
					__attribute__((\
						always_inline, used, \
						visibility("hidden")));
// unload :
extern char			__histo_unload(\
						t_histo__ *restrict const histo__,
						t_mem *restrict const mem__
						)
					__attribute__((\
						always_inline, used, \
						visibility("hidden")));
// add :
extern char			__histo_add(\
						t_histo__ *restrict const histo__,
						t_mem *restrict const mem__,
						const char *restrict const cmd__
						)
					__attribute__((\
						always_inline, used, \
						visibility("hidden")));
// find
extern char			__histo_find(\
						t_histo__ *restrict const histo__,
						const unsigned int index__
						)
					__attribute__((\
						always_inline, used, \
						visibility("hidden")));
// show :
extern char			__histo_show(\
						t_histo__ *restrict const histo__,
						t_visual *restrict const visual__
						)
					__attribute__((\
						always_inline, used, \
						visibility("hidden")));

#endif
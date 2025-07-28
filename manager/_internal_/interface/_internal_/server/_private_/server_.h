/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _manager.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/05/23 15:17:06 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER__H
# define SERVER__H

# pragma once

/* -------- modules --------- */
	// --- internal ---- //
# include "../_internal_/server__.h"

	// ---- locals ----- //
# include "./types__.h"

/* ------- prototypes ------- */
	// ---- private ---- //
// access :
extern t_server_	*_server_get(\
						t_server_	*restrict const new_
						)
					__attribute__((\
						hot, used, \
						visibility("hidden")));
extern t_server_	*_server_self(void)
					__attribute__((\
						hot, used, \
						visibility("hidden")));
// add :
extern char			_server_add(\
						t_signal_ *restrict const signal_,
						const void *restrict const handler_
						)
					__attribute__((\
						always_inline, used, \
						visibility("hidden")));
// remove :
extern char			__server_reset(void)
					__attribute__((\
						cold, used, \
						visibility("hidden")));
// handler :
extern char			_server_sigint_handler(\
						int signal_,
						t_infos_ *infos_,
						void *context_
						)
					__attribute__((\
						hot, used, \
						visibility("hidden")));
extern char			_server_sigquit_handler(\
						int signal_,
						t_infos_ *infos_,
						void *context_
						)
					__attribute__((\
						cold, used, \
						visibility("hidden")));
extern char			_server_sigstop_handler(\
						int signal_,
						t_infos_ *infos_,
						void *context_
						)
					__attribute__((\
						cold, used, \
						visibility("hidden")));

#endif 
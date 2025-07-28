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

#ifndef SERVER___H
# define SERVER___H

# pragma once

/* -------- modules --------- */
	// ---- locals ----- //
# include "./types__.h"

	// ---- private ---- //
# include "../_private_/server_.h"

/* ------- prototypes ------- */
	// --- internal ---- //
// init :
extern char			__server_init(\
						t_server_ *restrict const server__
						)
					__attribute__((\
						always_inline, used, \
						visibility("hidden")));
// access :
extern t_server_	*__server_get(\
						t_server_	*restrict const new__
						)
					__attribute__((\
						always_inline, used, \
						visibility("hidden")));
extern t_server_	*__server_self(void)
					__attribute__((\
						always_inline, used, \
						visibility("hidden")));
// add :
extern char			__server_add(\
						t_signal_ *restrict const signal__,
						const void *restrict const handler__
						)
					__attribute__((\
						always_inline, used, \
						visibility("hidden")));
// remove :
extern char			__server_reset(void)
					__attribute__((\
						always_inline, used, \
						visibility("hidden")));
// handler :
extern char			__server_sigint_handler(\
						const int signal__
						)
					__attribute__((\
						always_inline, used, \
						visibility("hidden")));
extern char			__server_sigquit_handler(\
						const int signal__
						)
					__attribute__((\
						always_inline, used, \
						visibility("hidden")));
extern char			__server_sigstop_handler(\
						const int signal__
						)
					__attribute__((\
						always_inline, used, \
						visibility("hidden")));

#endif
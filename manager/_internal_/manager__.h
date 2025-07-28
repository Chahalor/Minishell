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

#ifndef MANAGER___H
# define MANAGER___H

# pragma once

/* -------- modules --------- */
	// ---- locals ----- //
# include "./types__.h"
# include "memory/_public_/memory.h"
# include "env/_public_/env.h"
# include "proc/_public_/proc.h"
# include "interface/_public_/interface.h"

	// ---- private ---- //
# include "../_private_/manager_.h"

/* ------- prototypes ------- */
	// --- internal ---- //
// init :
extern char			__manager_init(\
						t_manager_ *restrict const manager__
						)
					__attribute__((\
						always_inline, used, \
						visibility("hidden")));
// setup :
extern t_manager_	*__manager_setup(\
						char **env__
						)
					__attribute__((\
						always_inline, used, \
						visibility("hidden")));
// access :
extern t_manager_	*__manager(\
						t_manager_	*restrict const new__
						)
					__attribute__((\
						always_inline, used, \
						visibility("hidden")));

#endif
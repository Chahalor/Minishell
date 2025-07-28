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

#ifndef INTERFACE___H
# define INTERFACE___H

# pragma once

/* -------- modules --------- */
	// ---- locals ----- //
# include "./types__.h"
# include "/interraction/_public_/interraction.h"
# include "/server/_public_/server.h"

	// ---- private ---- //
# include "../_private_/interface_.h"

/* ------- prototypes ------- */
	// --- internal ---- //
// init :
extern char			__interface_init(\
						t_interface_ *restrict const interface__
						)
					__attribute__((\
						always_inline, used, \
						visibility("hidden")));
// access :
extern t_interface_	*__interface_get(\
						t_interface_	*restrict const new__
						)
					__attribute__((\
						always_inline, used, \
						visibility("hidden")));
extern t_interface_	*__interface_self(void)
					__attribute__((\
						always_inline, used, \
						visibility("hidden")));
// ...

#endif
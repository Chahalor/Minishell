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

#ifndef MANAGER__H
# define MANAGER__H

# pragma once

/* -------- modules --------- */
	// --- internal ---- //
# include "../_internal_/manager__.h"

	// ----- local ----- //
# include "./types_.h"

/* ------- prototypes ------- */
	// ---- private ---- //
// init :
extern char			_manager_init(\
						t_manager_ *restrict const manager_
						)
					__attribute__((\
						always_inline, used, \
						visibility("hidden")));
// access :
extern t_manager_	*_manager(\
						t_manager_	*restrict const new_
						)
					__attribute__((\
						hot, used, \
						visibility("hidden")));

#endif
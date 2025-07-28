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

#ifndef INTERFACE_H
# define INTERFACE_H

# pragma once

/* -------- modules --------- */
	// --- internal ---- //
# include "../_internal_/interface__.h"

	// ---- locals ----- //
# include "./types.h"

/* ------- prototypes ------- */
	// ---- public ----- //
// init :
extern char	interface_init(\
				t_interface *restrict const interface
				)
			__attribute__((\
				always_inline, used, \
				visibility("default")));

#endif
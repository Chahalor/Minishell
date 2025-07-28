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

#ifndef VISUAL_H
# define VISUAL_H

# pragma once

/* -------- modules --------- */
	// --- internal ---- //
# include "../_internal_/visual__.h"

	// ----- local ----- //
# include "./types.h"

/* ------- prototypes ------- */
	// ---- public ----- //
// init :
extern char	visual_init(\
				t_visual *restrict const visual
				)
			__attribute__((\
				always_inline, used, \
				visibility("default")));

#endif
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

#ifndef PROC__H
# define PROC__H

# pragma once

/* -------- modules --------- */
	// --- internal ---- //
# include "../_internal_/proc__.h"

	// ---- locals ----- //
# include "./types_.h"

/* ------- prototypes ------- */
	// ---- private ---- //
// access :
extern t_proc_	*_proc_get(\
					t_proc_	*restrict const new_
					)
				__attribute__((\
					hot, used \
					visibility("hidden")));
extern t_proc_	*_proc_self(void)
				__attribute__((\
					hot, used \
					visibility("hidden")));
// proc :
// ...

#endif
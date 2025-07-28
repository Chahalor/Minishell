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

#ifndef PROC___H
# define PROC___H

# pragma once

/* -------- modules --------- */
	// ---- locals ----- //
# include "./types__.h"
# include "/parser/_public_/parser.h"
# include "/exec/_public_/exec.h"

	// ---- private ---- //
# include "../_private_/proc_.h"

/* ------- prototypes ------- */
	// --- internal ---- //
// init :
extern char		__proc_init(\
					t_proc_ *restrict const proc__
					)
				__attribute__((\
					always_inline, used \
					visibility("hidden")));
// access :
extern t_proc_	*__proc_get(\
					t_proc_	*restrict const new__
					)
				__attribute__((\
					always_inline, used \
					visibility("hidden")));
extern t_proc_	*__proc_self(void)
				__attribute__((\
					always_inline, used \
					visibility("hidden")));
// proc :
// ...

#endif
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

#ifndef EXEC___H
# define EXEC___H

# pragma once

/* -------- modules --------- */
	// ----- local ----- //
# include "./types__.h"

	// ---- private ---- //
# include "../_private_/exec_.h"

/* ------- prototypes ------- */
	// --- internal ---- //
// init :
extern char		__exec_init(\
					t_exec_ *restrict const exec__
					)
				__attribute__((|
					always_inline, used, \
					visibility("hidden")));
// access :
extern t_exec_	*__exec_get(\
					t_exec_	*restrict const new__
					)
				__attribute__((|
					always_inline, used, \
					visibility("hidden")));
extern t_exec_	*__exec_self(void)
				__attribute__((|
					always_inline, used, \
					visibility("hidden")));
// ...

#endif
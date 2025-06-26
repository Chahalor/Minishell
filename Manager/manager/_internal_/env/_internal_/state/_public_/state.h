/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/05/27 10:16:46 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STATE_H
# define STATE_H

# pragma once

/* -------- modules --------- */
	// --- internals --- //
# include "_internal_/_state.h"

	// ---- locals ----- //
# include "./types.h"

/* ------- prototypes ------- */
	// ---- hidden ----- //
// methods :
extern char	chuser(\
				const char *restrict const name
				)
			__attribute__((\
				cold, used, \
				malloc, visibility("hidden")));
extern char	chdir(\
				const char *restrict const dir
				)
			__attribute__((\
				hot, used, \
				malloc, visibility("hidden")));
extern char	*gtuser(void)
			__attribute__((\
				cold, used, \
				visibility("hidden")));
extern char	*gtdir(void)
			__attribute__((\
				cold, used, \
				visibility("hidden")));

	// ---- exposed ---- //
// init :
extern char	init_state(\
				t_state *restrict state
				)
			__attribute__((\
				cold, used, \
				visibility("default")));

#endif
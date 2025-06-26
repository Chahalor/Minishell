/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/05/26 12:39:46 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# pragma once

/* -------- modules --------- */
	// --- internals --- //
# include "_internal_/_env.h"

	// ---- locals ----- //
# include "./types.h"

/* ------- prototypes ------- */
	// ---- hidden ----- //
// methods :
extern char load_env(void)
			__attribute__((\
				cold, used, \
				visibility("hidden")));
extern char *gthome(void)
			__attribute__((\
				hot, used, \
				visibility("hidden")));
extern char *gtpath(void)
			__attribute__((\
				hot, used, \
				visibility("hidden")));
extern char set(\
				const char *restrict const var
				)
			__attribute__((\
				hot, used, \
				visibility("hidden")));
extern char unset(\
				const char *restrict const var
				)
			__attribute__((\
				hot, used, \
				visibility("hidden")));
// >>>
extern char	*find(\
				const unsigned char type,
				const char *restrict const target
				)
			__attribute__((\
				hot, used, \
				visibility("hidden")));

	// ---- exposed ---- //
// init :
extern char	init_env(\
				t_env *restrict env
				)
			__attribute__((\
				cold, used, \
				visibility("default")));

#endif
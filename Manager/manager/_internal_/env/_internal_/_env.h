/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _env.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/05/26 12:39:02 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _ENV_H
# define _ENV_H

# pragma once

/* -------- modules --------- */
	// ---- locals ----- //
# include "./_types.h"

	// ---- globals ---- //
# include "memory/memory.h"
# include "utils/utils.h"
# include "manager.h"

	// ---- public ----- //
# include "env.h"

/* ------- prototypes ------- */
	// ---- hidden ----- //
// init :
extern char	_init_env(\
				t_env_ *restrict env
				)
			__attribute__((\
				always_inline, used, \
				visibility("hidden")));
// methods :
extern char _load_env(\
				t_env_ *restrict const env
				)
			__attribute__((\
				always_inline, used, \
				visibility("hidden")));
extern char *_gthome(\
				t_env_ *restrict const env
				)
			__attribute__((\
				always_inline, used, \
				visibility("hidden")));
extern char *_gtpath(\
				t_env_ *restrict const env
				)
			__attribute__((\
				always_inline, used, \
				visibility("hidden")));
extern char _set(\
				t_env_ *restrict const env,
				const char *restrict const var
				)
			__attribute__((\
				always_inline, used, \
				visibility("hidden")));
extern char _unset(\
				t_env_ *restrict const env,
				const char *restrict const var
				)
			__attribute__((\
				always_inline, used, \
				visibility("hidden")));
// >>>
extern char	*_find(\
				const t_state *restrict const state,
				const t_env *restrict const env,
				const unsigned char type,
				const char *restrict const target
				)
			__attribute__((\
				always_inline, used, \
				visibility("hidden")));

#endif
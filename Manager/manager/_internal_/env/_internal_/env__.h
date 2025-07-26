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

#ifndef ENV___H
# define ENV___H

# pragma once

/* -------- modules --------- */
	// ---- locals ----- //
# include "./types__.h"
# include "state/_public_/state.h"
# include "history/_public_/history.h"

	// ---- private ---- //
# include "../_private_/env_.h"

/* ------- prototypes ------- */
	// --- internal ---- //
// init :
extern char		__env_init(\
					t_env_ *restrict const env__
					)
				__attribute__((\
					always_inline, used, \
					visibility("hidden")));
// access :
extern t_env_	*__env_get(\
					t_env_	*restrict const new__
					)
				__attribute__((\
					always_inline, used, \
					visibility("hidden")));
extern t_env_	*__env_self(void)
				__attribute__((\
					always_inline, used, \
					visibility("hidden")));
// load :
extern char 	__env_chhome(\
					t_env_ *restrict const env__,
					t_mem *restrict const mem__,
					const char *restrict const new__
					)
				__attribute__((\
					always_inline, used, \
					visibility("hidden")));
extern char		__env_chpath(\
					t_env_ *restrict const env__,
					t_mem *restrict const mem__,
					const char *restrict const new__
					)
				__attribute__((\
					always_inline, used, \
					visibility("hidden")));
// find :
extern char 	*__env_home(\
					t_env_ *restrict const env__
					)
				__attribute__((\
					always_inline, used, \
					visibility("hidden")));
extern char		*__env_path(\
					t_env_ *restrict const env__,
					)
				__attribute__((\
					always_inline, used, \
					visibility("hidden")));
extern char		**__env_vars(\
					t_env_ *restrict const env__,
					)
				__attribute__((\
					always_inline, used, \
					visibility("hidden")));
extern char		*__env_find(\
					t_env_ *restrict const env__,
					t_mem *restrict const mem__,
					const char *restrict const target__
					)
				__attribute__((\
					always_inline, used, \
					visibility("hidden")));
// add :
extern char 	__env_set(\
					t_env_ *restrict const env__,
					t_mem *restrict const mem__,
					const char *restrict const target__,
					const char *restrict const content__
					)
				__attribute__((\
					always_inline, used, \
					visibility("hidden")));
extern char		__env_unset(\
					t_env_ *restrict const env__,
					t_mem *restrict const mem__,
					const char *restrict const target__
					)
				__attribute__((\
					always_inline, used, \
					visibility("hidden")));

#endif
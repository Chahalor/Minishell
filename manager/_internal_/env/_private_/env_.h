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

#ifndef ENV__H
# define ENV__H

# pragma once

/* -------- modules --------- */
	// --- internal ---- //
# include "../_internal_/env__.h"

	// ---- locals ----- //
# include "./types_.h"

/* ------- prototypes ------- */
	// ---- private ---- //
// access :
extern t_env_	*_env_get(\
					t_env_	*restrict const new_
					)
				__attribute__((\
					hot, used, \
					visibility("hidden")));
extern t_env_	*_env_self(void)
				__attribute__((\
					hot, used, \
					visibility("hidden")));
// load :
extern char 	_env_chhome(\
					const char *restrict const new_
					)
				__attribute__((\
					cold, used, \
					visibility("hidden")));
extern char		_env_chpath(\
					const char *restrict const new_
					)
				__attribute__((\
					cold, used, \
					visibility("hidden")));
// find :
extern char 	*_env_home(void)
				__attribute__((\
					cold, used, \
					visibility("hidden")));
extern char		*_env_path(void)
				__attribute__((\
					hot, used, \
					visibility("hidden")));
extern char		**_env_vars(void)
				__attribute__((\
					hot, used, \
					visibility("hidden")));
extern char		*_env_find(\
					const char *restrict const target_
					)
				__attribute__((\
					hot, used, \
					visibility("hidden")));
// add :
extern char 	_env_set(\
					const char *restrict const target_,
					const char *restrict const content_
					)
				__attribute__((\
					hot, used, \
					visibility("hidden")));
extern char		_env_unset(\
					const char *restrict const target_
					)
				__attribute__((\
					hot, used, \
					visibility("hidden")));

#endif
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

#ifndef _MANAGER_H
# define _MANAGER_H

# pragma once

/* -------- modules --------- */
	// ---- locals ----- //
# include "./_types.h"

	// ---- globals ---- //
// utils :
# include "memory/memory.h"
# include "utils/utils.h"
// main :
# include "env/env.h"
# include "state/state.h"
# include "history/history.h"

	// ---- public ----- //
# include "manager.h"

/* --------- enums ---------- */
	// ---- manager ---- //
// TODO: shall correct this shit.
// sizes and offsets of the manager.
enum e_sizes_	// v.1. >>> .
{
	// sizes :
	// manager internal :
	params_size = (\
					sizeof(t_params_)),
	env_size = (\
				sizeof(t_env)),
	state_size = (\
					sizeof(t_state)
					// we can either do a limited size pre-allocation or
					// granular dynamic one.
					//+ MAX_USER_NAME_LEN
					//+ MAX_PATH_LEN
					//+ MAX_HOME_PATH_LEN
					//+ the PATH (env) size.
					),
	histo_size = (\
					sizeof(t_histo)
					+ SHELL_HISTORY_PATH_LEN),
	// manager local :
	command_size = (\
					sizeof(t_command_)),
	redir_size = (\
					sizeof(t_redir_)),
	section_size = (\
					sizeof(t_section_)),
	manager_size = (\
					sizeof(t_manager_)),
	// offsets :
	// manager internal :
	offset_to_params = (0),
	// manager local :
	// ...
};

/* ------- prototypes ------- */
	// ---- hidden ----- //
// init :
# undef _INIT_C
# undef INIT_C
// ...
// setup :
extern t_manager_		*_setup_manager(\
							char *restrict *restrict const env
							)
						__attribute__((\
							always_inline, used, \
							visibility("hidden")));
// access :
extern t_manager_		*_get_manager(\
							t_manager_	*restrict const new
							)
						__attribute__((\
							always_inline, used, \
							visibility("hidden")));

#endif
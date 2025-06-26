/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _history.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/06/12 16:00:10 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _HISTORY_H
# define _HISTORY_H

# pragma once

/* -------- modules --------- */
	// ---- locals ----- //
# include "./_types.h"

	// ---- globals ---- //
# include "memory/memory.h"
# include "utils/utils.h"
# include "reader/reader.h"
# include "manager.h"

	// ---- public ----- //
# include "history.h"

/* --------- enums ---------- */
	// ---- memory ----- //
enum e_sizes_	// v.1. >>> .
{
	// sizes :
	_history_size = (\
					sizeof(t_mem_)),
	// offsets :
	_offset_to_path = (0),
	_offset_to_content = (\
							_offset_to_path
							+ (256 * sizeof(char))),	// we'll assume the path allocation size is 256.
};

/* ------- prototypes ------- */
	// ---- hidden ----- //
// init :
extern char				_init_history(\
							t_histo_ *restrict history
							)
						__attribute__((\
							always_inline, used, \
							visibility("hidden")));
// methods :
extern char				_load_history(\
							t_histo_ *restrict const history
							)
						__attribute__((\
							always_inline, used, \
							visibility("hidden")));
extern void				_unload_history(\
							t_histo_ *restrict const history
							)
						__attribute__((\
							always_inline, used, \
							visibility("hidden")));
extern char				_show_history(\
							t_histo_ *restrict const history
							)
						__attribute__((\
							always_inline, used, \
							visibility("hidden")));
extern char				_add_entry(\
							t_histo_ *restrict const history,
							const char *restrict const command
							)
						__attribute__((\
							always_inline, used, \
							visibility("hidden")));
extern char 			*_get_entry(\
							t_histo_ *restrict const history,
							const unsigned int index
							)
						__attribute__((\
							always_inline, used, \
							visibility("hidden")));

#endif
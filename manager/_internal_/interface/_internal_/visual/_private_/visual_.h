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

#ifndef VISUAL__H
# define VISUAL__H

# pragma once

/* -------- modules --------- */
	// --- internal ---- //
# include "../_internal_/visual__.h"

	// ----- local ----- //
# include "./types_.h"

/* ------- prototypes ------- */
	// ---- private ---- //
// access :
extern t_visual_	*_visual_get(\
						t_visual_	*restrict const new_
						)
					__attribute__((\
						hot, used, \
						visibility("hidden")));
extern t_visual_	*_visual_self(void)
					__attribute__((\
						hot, used, \
						visibility("hidden")));
// add :
extern int			_visual_add(\
						const char ltr_
						)
					__attribute__((\
						hot, used, \
						visibility("hidden")));
extern int			_visual_str(\
						const char *restrict const str_
						)
					__attribute__((\
						always_inline, used, \
						visibility("hidden")));
extern int			_visual_hex(\
						unsigned long val_,
						const char *const restrict base_
						)
					__attribute__((\
						always_inline, used, \
						visibility("hidden")));
extern int			_visual_ptr(\
						const void *restrict const ptr_
						)
					__attribute__((\
						always_inline, used, \
						visibility("hidden")));
extern int			_visual_dec(\
						long val_
						)
					__attribute__((\
						always_inline, used, \
						visibility("hidden")));
// proc :
extern int			_visual_select(\
						const char *restrict const str_,
						va_list args_
						)
					__attribute__((\
						hot, used, \
						visibility("hidden")));
extern int			_visual_proc(\
						const char *restrict const str_,
						va_list args_
						)
					__attribute__((\
						always_inline, used, \
						visibility("hidden")));
// visual :
extern int			_visual_printf(\
						const char *const restrict format_,
						...
						)
					__attribute__((\
						hot, used, \
						visibility("hidden")));
extern int			_visual_rprintf(\
						const char *const restrict format_,
						...
						)
					__attribute__((\
						hot, used, \
						visibility("hidden")));
extern int			_visual_fprintf(\
						const int fd_,
						const char *const restrict format_,
						...
						)
					__attribute__((\
						hot, used, \
						visibility("hidden")));
extern int			_visual_sprintf(\
						char *const restrict buffer_,
						const char *const restrict format_,
						...
						)
					__attribute__((\
						hot, used, \
						visibility("hidden")));
extern char			_visual_perror(\
						const char *const restrict format_,
						...
						)
					__attribute__((\
						hot, used, \
						visibility("hidden")));

#endif
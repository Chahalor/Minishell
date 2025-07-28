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

#ifndef VISUAL___H
# define VISUAL___H

# pragma once

/* -------- modules --------- */
	// ----- local ----- //
# include "./types__.h"

	// ---- private ---- //
# include "../_private_/visual_.h"

/* ------- prototypes ------- */
	// --- internal ---- //
// init :
extern char			__visual_init(\
						t_visual_ *restrict const visual__
						)
					__attribute__((\
						always_inline, used, \
						visibility("hidden")));
// access :
extern t_visual_	*__visual_get(\
						t_visual_	*restrict const new__
						)
					__attribute__((\
						always_inline, used, \
						visibility("hidden")));
extern t_visual_	*__visual_self(void)
					__attribute__((\
						always_inline, used, \
						visibility("hidden")));
// add :
extern int			__visual_add(\
						t_visual__ *restrict const visual__,
						const char ltr__
						)
					__attribute__((\
						always_inline, used, \
						visibility("hidden")));
extern int			__visual_str(\
						t_visual__ *restrict const visual__,
						const char *restrict const str__
						)
					__attribute__((\
						always_inline, used, \
						visibility("hidden")));
extern int			__visual_hex(\
						t_visual__ *restrict const visual__,
						unsigned long val__,
						const char *const restrict base__
						)
					__attribute__((\
						always_inline, used, \
						visibility("hidden")));
extern int			__visual_ptr(\
						t_visual__ *restrict const visual__,
						const void *restrict const ptr__
						)
					__attribute__((\
						always_inline, used, \
						visibility("hidden")));
extern int			__visual_dec(\
						t_visual__ *restrict const visual__,
						long val__
						)
					__attribute__((\
						always_inline, used, \
						visibility("hidden")));
// proc :
extern int			__visual_select(\
						t_visual__ *restrict const visual__,
						const char *restrict const str__,
						va_list args__
						)
					__attribute__((\
						always_inline, used, \
						visibility("hidden")));
extern int			__visual_proc(\
						t_visual_ *restrict const visual__,
						t_mem *restrict const mem__,
						const char *restrict const str__,
						va_list args__
						)
					__attribute__((\
						always_inline, used, \
						visibility("hidden")));
// visual :
extern int			__visual_printf(\
						t_visual__ *restrict const visual__,
						const char *const restrict format__,
						va_list args__
						)
					__attribute__((\
						always_inline, used, \
						visibility("hidden")));
extern int			__visual_rprintf(\
						t_visual__ *restrict const visual__,
						const char *const restrict format__,
						va_list args__
						)
					__attribute__((\
						always_inline, used, \
						visibility("hidden")));
extern int			__visual_fprintf(\
						t_visual__ *restrict const visual__,
						const int fd__,
						const char *const restrict format__,
						va_list args__
						)
					__attribute__((\
						always_inline, used, \
						visibility("hidden")));
extern int			__visual_sprintf(\
						t_visual__ *restrict const visual__,
						char *const restrict buffer__,
						const char *const restrict format__,
						va_list args__
						)
					__attribute__((\
						always_inline, used, \
						visibility("hidden")));
extern char			__visual_perror(\
						t_visual__ *restrict const visual__,
						const char *const restrict format__,
						va_list args__
						)
					__attribute__((\
						always_inline, used, \
						visibility("hidden")));


#endif
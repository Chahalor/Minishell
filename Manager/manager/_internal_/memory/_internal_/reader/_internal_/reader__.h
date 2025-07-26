/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader__.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/06/27 16:50:53 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READER___H
# define READER___H

# pragma once

/* -------- modules --------- */
	// ----- local ----- //
# include "./types__.h"

	// ---- private ---- //
# include "../_private_/reader_.h"

/* ------- prototypes ------- */
	// --- internal ---- //
// init :
extern char			__reader_init(\
						t_reader_ *restrict const reader__
						)
					__attribute__((\
						always_inline, used, \
						visibility("hidden")));
// setup :
extern char			__reader_setup(\
						t_reader_ **reader__,
						const t_mem *restrict const mem__
						)
					__attribute__((\
						always_inline, used, \
						visibility("hidden")));
// access :
extern t_reader_	*__reader_get(\
						t_reader_	*restrict const new__
						)
					__attribute__((\
						always_inline, used, \
						visibility("hidden")));
extern t_reader_	*__reader_self(void)
					__attribute__((\
						always_inline, used, \
						visibility("hidden")));
// add :
extern char			__reader_add_container(\
						const t_reader__ *restrict const reader__,
						const t_mem *restrict const mem__,
						const unsigned int target__,
						void **buffer__
						)
					__attribute__((\
						always_inline, used, \
						visibility("hidden")));
// remove :
extern char			__reader_remove(\
						const unsigned char *restrict const mode__,
						const char *restrict const target__
						)
					__attribute__((\
						always_inline, used, \
						visibility("hidden")));
extern char			__reader_remove_container_fd(\
						const t_reader__ *restrict const reader__,
						const t_mem *restrict const mem__,
						const unsigned int target__
						)
					__attribute__((\
						always_inline, used, \
						visibility("hidden")));
extern char			__reader_remove_container_file(\
						const t_reader__ *restrict const reader__,
						const t_mem *restrict const mem__,
						const char *restrict const target__
						)
					__attribute__((\
						always_inline, used, \
						visibility("hidden")));
extern void			__reader_remove_all(\
						const t_reader__ *restrict const reader__
						)
					__attribute__((\
						always_inline, used, \
						visibility("hidden")));
// find :
extern char			__reader_find(\
						const unsigned char *restrict const mode__,
						const char *target__,
						void **buffer__
						)
					__attribute__((\
						always_inline, used, \
						visibility("hidden")));
extern char			__reader_find_container_fd(\
						const t_reader__ *restrict const reader__,
						const char *restrict const target__,
						void **buffer__
						)
					__attribute__((\
						always_inline, used, \
						visibility("hidden")));
extern char			__reader_find_container_name(\
						const t_reader__ *restrict const reader__,
						t_mem *restrict const mem__,
						const char *restrict const target__,
						void **buffer__
						)
					__attribute__((\
						always_inline, used, \
						visibility("hidden")));
extern char 		__reader_find_container(\
						const unsigned char *restrict const mode__,
						const char *target__,
						void **buffer__
						)
					__attribute__((\
						always_inline, used, \
						visibility("hidden")));
extern char			__reader_find_file(\
						const unsigned char *restrict const mode__,
						const char *restrict const target__,
						void **buffer__
							)
					__attribute__((\
						always_inline, used, \
						visibility("hidden")));
// read :
extern char			__reader_proc(\
						t_reader__ *restrict const reader__,
						const t_mem *restrict const mem__,
						const char *restrict const target__,
						char **buffer__
						)
					__attribute__((\
						always_inline, used, \
						visibility("hidden")));
extern char			__reader_read(\
						t_container_ **container__,
						const t_mem *restrict const mem__,
						const unsigned int target__,
						char **buffer__
						)
					__attribute__((\
						always_inline, used, \
						visibility("hidden")));

#endif
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

#ifndef READER__H
# define READER__H

# pragma once

/* -------- modules --------- */
	// --- internal ---- //
# include "../_internal_/reader__.h"

	// ----- local ----- //
# include "./types_.h"

/* ------- prototypes ------- */
	// ---- private ---- //
// init :
extern char			_reader_init(\
						t_reader_ *restrict const reader_
						)
					__attribute__((\
						always_inline, used, \
						visibility("hidden")));
// access :
extern t_reader_	*_reader_get(\
						t_reader_	*restrict const new_
						)
					__attribute__((\
						hot, used, \
						visibility("hidden")));
extern t_reader_	*_reader_self(void)
					__attribute__((\
						hot, used, \
						visibility("hidden")));
// add :
extern char			_reader_add_container(\
						const unsigned int target_,
						void **buffer_
						)
					__attribute__((\
						cold, used, \
						visibility("hidden")));
// remove :
extern char			_reader_remove(\
						const unsigned char *restrict const mode_,
						const char *restrict const target_
						)
					__attribute__((\
						hot, used, \
						visibility("hidden")));
extern char			_reader_remove_container_fd(\
						const char *restrict const target_
						)
					__attribute__((\
						hot, used, \
						visibility("hidden")));
extern char			_reader_remove_container_file(\
						const char *restrict const target_
						)
					__attribute__((\
						cold, used, \
						visibility("hidden")));
extern char			_reader_remove_all(
						const char *restrict const target_
						)
					__attribute__((\
						cold, used, \
						visibility("hidden")));
// check :
extern char			_reader_check(\
						const char *restrict const path_,
						const int mode_
						)
					__attribute__((\
						hot, used, \
						visibility("hidden")));
extern char			_reader_check_presence(\
						const char *restrict const path_,
						const char *restrict const name_,
						char **buffer_
						)
					__attribute__((\
						hot, used, \
						visibility("hidden")));
// find :
extern char			_reader_find(\
						const unsigned char *restrict const mode_,
						const char *restrict const target_,
						void **buffer_
						)
					__attribute__((\
						hot, used, \
						visibility("hidden")));
extern char			_reader_find_container_fd(\
						const char *restrict const target_,
						void **buffer_
						)
					__attribute__((\
						hot, used, \
						visibility("hidden")));
extern char 		_reader_find_container_name(\
						const char *restrict const target_,
						void **buffer_
						)
					__attribute__((\
						hot, used, \
						visibility("hidden")));
extern char 		_reader_find_container(\
						const unsigned char *restrict const mode_,
						const char *restrict const target_,
						void **buffer_
						)
					__attribute__((\
						hot, used, \
						visibility("hidden")));
extern char			_reader_find_file(\
						const unsigned char *restrict const mode_,
						const char *restrict const target_,
						void **buffer_
						)
					__attribute__((\
						cold, used, \
						visibility("hidden")));
// read :
extern char			_reader_proc(\
						const char *restrict const target_,
						char **buffer_
						)
					__attribute__((\
						hot, used, \
						visibility("hidden")));
extern char			_reader_read(\
						t_container_ **container_,
						const t_mem *restrict const mem_,
						const unsigned int target_,
						char **buffer_
						)
					__attribute__((\
						hot, used, \
						visibility("hidden")));

#endif
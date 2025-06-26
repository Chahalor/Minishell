/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/06/24 16:23:24 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMORY__H
# define MEMORY__H

# pragma once

/* -------- modules --------- */
	// --- internal ---- //
# include "../_internal_/memory__.h"

	// ----- local ----- //
# include "./types_.h"

/* ------- prototypes ------- */
	// ---- private ---- //
// format :
extern unsigned int	_mem_format(\
						const unsigned char *restrict const mode_,
						void *area_,
						const unsigned int index_
						)
					__attribute__((\
						hot, used, \
						visibility("hidden")));
extern unsigned int	_mem_format_collide(\
						const t_mem__ *restrict const mem_,
						void *area_,
						const unsigned int index_
						)
					__attribute__((\
						hot, used, \
						visibility("hidden")));
extern unsigned int	_mem_format_correspond(\
						const t_mem__ *restrict const mem_,
						void *area_,
						const unsigned int index_
						)
					__attribute__((\
						hot, used, \
						visibility("hidden")));
// access :
extern t_mem_		*_mem_self(void)
					__attribute__((\
						always_inline, used, \
						visibility("hidden")));
extern t_mem_		*_mem_get(\
						t_mem_	*restrict const new_
						)
					__attribute__((\
						hot, used, \
						visibility("hidden")));
extern void			*_mem_section(\
						void **ptr_,
						const unsigned int size_
						)
					__attribute__((\
						always_inline, used, \
						visibility("hidden")));
extern t_mem_alloc_	*_mem_to_alloc(\
						void *ptr_
						)
					__attribute__((\
						hot, used, \
						visibility("hidden")));
// manage :
extern int			_mem_manage(\
						const unsigned char *restrict const mode_,
						void *area_,
						const unsigned int size_
						)
					__attribute__((\
						hot, used, \
						visibility("hidden")));
// alloc :
extern char			_mem_alloc(\
						const unsigned char *restrict const mode_,
						void **ptr_,
						const unsigned int size_,
						const unsigned char type_
						)
					__attribute__((\
						hot, used, \
						visibility("hidden")));
extern char			_mem_alloc_new(\
						void **ptr_,
						const unsigned int size_,
						const unsigned char type_
						)
					__attribute__((\
						hot, used, \
						visibility("hidden")));
extern char			_mem_realloc(\
						void **ptr_,
						const unsigned int size_,
						const unsigned char type_
						)
					__attribute__((\
						hot, used, \
						visibility("hidden")));
// clean :
extern char			_mem_clean(\
						const unsigned char *restrict const mode_,
						const char code_,
						void *ptr_,
						const unsigned int size_
						)
					__attribute__((\
						hot, used, \
						visibility("hidden")));
extern char			_mem_clean_buffer(\
						const char code_,
						void *ptr_,
						const unsigned int size_
						)
					__attribute__((\
						hot, used, \
						visibility("hidden")));
extern char			_mem_clean_ptr(\
						const char code_,
						void *ptr_,
						const unsigned int size_
						)
					__attribute__((\
						hot, used, \
						visibility("hidden")));
extern char			_mem_clean_all(\
						const char code_,
						void *ptr_,
						const unsigned int size_
						)
					__attribute__((\
						cold, used, \
						visibility("hidden")));
// size :
extern unsigned int	_mem_size(\
						const unsigned char *restrict const mode_,
						void *area_,
						const char *restrict const end_
						)
					__attribute__((\
						hot, used, \
						visibility("hidden")));
extern unsigned int	_mem_word_len(\
						void *area_,
						const char *restrict const end_
						)
					__attribute__((\
						hot, used, \
						visibility("hidden")));
extern unsigned int	_mem_len(\
						void *area_,
						const char *restrict const end_
						)
					__attribute__((\
						hot, used, \
						visibility("hidden")));
// write :
extern char			_mem_write(\
						const unsigned char *restrict const mode_,
						void *dest_,
						void *data_,
						const unsigned int len_
						)
					__attribute__((\
						hot, used, \
						visibility("hidden")));
extern char			_mem_write_buffer(\
						const unsigned char spec__,
						void *dest_,
						void *data_,
						const unsigned int len_
						)
					__attribute__((\
						hot, used, \
						visibility("hidden")));
extern char			_mem_link(\
						const unsigned char spec__,
						void *dest_,
						void *data_,
						const unsigned int len_
						)
					__attribute__((\
						hot, used, \
						visibility("hidden")));
extern char			_mem_write_file(\
						const unsigned char spec__,
						void *dest_,
						void *data_,
						const unsigned int len_
						)
					__attribute__((\
						hot, used, \
						visibility("hidden")));
// read :
extern char			_mem_read(\
						const unsigned char *restrict const mode_,
						void *src_,
						void *dest_,
						const unsigned int len_
						)
					__attribute__((\
						hot, used, \
						visibility("hidden")));
extern char			_mem_read_buffer(\
						const unsigned char spec_,
						void *src_,
						void *dest_,
						const unsigned int len_
						)
					__attribute__((\
						hot, used, \
						visibility("hidden")));
extern char			_mem_read_file(\
						const unsigned char spec_,
						void *src_,
						void *dest_,
						const unsigned int len_
						)
					__attribute__((\
						cold, used, \
						visibility("hidden")));
// copy :
extern char			_mem_copy(\
						const unsigned char *restrict const mode_,
						void *src_,
						void *dest_,
						const unsigned int len_
						)
					__attribute__((\
						hot, used, \
						visibility("hidden")));
extern char			_mem_copy_raw(\
						void *src_,
						void *dest_,
						const unsigned int len_
						)
					__attribute__((\
						hot, used, \
						visibility("hidden")));
extern char			_mem_replace(\
						void *src_,
						void *dest_,
						const unsigned int len_
						)
					__attribute__((\
						hot, used, \
						visibility("hidden")));
// shift :
extern unsigned int	_mem_shift(\
						const unsigned char *restrict const mode_,
						void *restrict const area_,
						const unsigned char *restrict const val_
						)
					__attribute__((\
						hot, used, \
						visibility("hidden")));
extern unsigned int	_mem_shift_by(\
						const unsigned char spec_,
						void *restrict const area_,
						const unsigned char *restrict const val_
						)
					__attribute__((\
						hot, used, \
						visibility("hidden")));
extern unsigned int	_mem_rewind(\
						const unsigned char spec_,
						void *restrict const area_,
						const unsigned char *restrict const val_
						)
					__attribute__((\
						hot, used, \
						visibility("hidden")));
extern unsigned int	_mem_avoid_by(\
						const unsigned char spec_,
						void *restrict const area_,
						const unsigned char *restrict const val_
						)
					__attribute__((\
						hot, used, \
						visibility("hidden")));
// compare :
extern char			_mem_compare(\
						const char *const area_,
						const char *const target_,
						unsigned int *len_
						)
					__attribute__((\
						hot, used, \
						visibility("hidden")));
// search :
extern int			_mem_search(\
						const unsigned char *restrict const mode_,
						const void *restrict const area_,
						const void *restrict const target_
						)
					__attribute__((\
						hot, used, \
						visibility("hidden")));
extern int			_mem_search_data(\
						const unsigned char spec_,
						const void *const area_,
						const void *const target_
						)
					__attribute__((\
						hot, used, \
						visibility("hidden")));
extern int			_mem_search_keep(\
						const unsigned char spec_,
						const void *const area_,
						const void *const target_
						)
					__attribute__((\
						hot, used, \
						visibility("hidden")));
extern int			_mem_search_file(\
						const unsigned char spec_,
						const void *const area_,
						const void *const target_
						)
					__attribute__((\
						hot, used, \
						visibility("hidden")));

#endif
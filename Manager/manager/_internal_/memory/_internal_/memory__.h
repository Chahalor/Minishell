/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory__.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/06/24 16:24:38 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMORY___H
# define MEMORY___H

# pragma once

/* -------- modules --------- */
	// ----- local ----- //
# include "./types__.h"

	// ---- private ---- //
# include "../_private_/memory_.h"

/* ------- prototypes ------- */
	// --- internal ---- //
// init :
extern char			__mem_init(\
						t_mem_ *restrict const mem__
						)
					__attribute__((\
						always_inline, used, \
						visibility("hidden")));
// format :
extern unsigned int	__mem_format(\
						const t_mem__ *restrict mem__,
						const unsigned char *restrict const mode__,
						void *area__,
						const unsigned int index__
						)
					__attribute__((\
						always_inline, used, \
						visibility("hidden")));
extern unsigned int	__mem_format_collide(\
						unsigned char *area__,
						const unsigned int index__
						)
					__attribute__((\
						always_inline, used, \
						visibility("hidden")));
extern unsigned int	__mem_format_correspond(\
						const t_mem__ *restrict const mem__,
						unsigned char *area__,
						const unsigned int index__
						)
					__attribute__((\
						always_inline, used, \
						visibility("hidden")));
// access :
extern t_mem_		*__mem_get(\
						t_mem_	*restrict const new__
						)
					__attribute__((\
						always_inline, used, \
						visibility("hidden")));
extern t_mem_		*__mem_self(void)
					__attribute__((\
						always_inline, used, \
						visibility("hidden")));
extern void			*__mem_section(\
						void **ptr__,
						const unsigned int size__
						)
					__attribute__((\
						always_inline, used, \
						visibility("hidden")));
extern t_mem_alloc_	*__mem_to_alloc(\
						void *ptr__
						)
					__attribute__((\
						always_inline, used, \
						visibility("hidden")));
// manage :
extern int			__mem_manage(\
						t_mem__ *restrict const mem,
						const unsigned char *restrict const mode__,
						void *area__,
						const unsigned int size__
						)
					__attribute__((\
						always_inline, used, \
						visibility("hidden")));
// alloc :
extern char			__mem_alloc(\
						const unsigned char *restrict const mode__,
						void **ptr__,
						const unsigned int size__,
						const unsigned char type__
						)
					__attribute__((\
						always_inline, used, \
						visibility("hidden")));
extern char			__mem_alloc_new(\
						void **ptr__,
						const unsigned int size__,
						const unsigned char type__
						)
					__attribute__((\
						always_inline, used, \
						visibility("hidden")));
extern char			__mem_realloc(\
						void **ptr__,
						const unsigned int size__
						)
					__attribute__((\
						always_inline, used, \
						visibility("hidden")));
// clean :
extern char			__mem_clean(\
						const unsigned char *restrict const mode__,
						const char code__,
						void *ptr__,
						const unsigned int size__
						)
					__attribute__((\
						always_inline, used, \
						visibility("hidden")));
extern char			__mem_clean_buffer(\
						void *ptr__,
						const unsigned int size__
						)
					__attribute__((\
						always_inline, used, \
						visibility("hidden")));
extern char			__mem_clean_ptr(\
						void *ptr__,
						const unsigned int size__
						)
					__attribute__((\
						always_inline, used, \
						visibility("hidden")));
extern char			__mem_clean_all(\
						const char code__,
						void *ptr__
						)
					__attribute__((\
						always_inline, used, \
						visibility("hidden")));
// size :
extern unsigned int	__mem_size(\
						const unsigned char *restrict const mode__,
						void *area__,
						const char *restrict const end__
						)
					__attribute__((\
						always_inline, used, \
						visibility("hidden")));
extern unsigned int	__mem_word_len(\
						void *area__,
						const char *restrict const end__
						)
					__attribute__((\
						always_inline, used, \
						visibility("hidden")));
extern unsigned int	__mem_len(\
						void *area__,
						const char *restrict const end__
						)
					__attribute__((\
						always_inline, used, \
						visibility("hidden")));
// write :
extern char			__mem_write(\
						const unsigned char *restrict const mode__,
						void *dest__,
						void *data__,
						const unsigned int len__
						)
					__attribute__((\
						always_inline, used, \
						visibility("hidden")));
extern char			__mem_write_buffer(\
						const unsigned char spec__,
						void *dest__,
						void *data__,
						const unsigned int len__
						)
					__attribute__((\
						always_inline, used, \
						visibility("hidden")));
extern char			__mem_link(\
						void *dest__,
						void *data__,
						const unsigned int len__
						)
					__attribute__((\
						always_inline, used, \
						visibility("hidden")));
extern char			__mem_write_file(\
						void *dest__,
						void *data__,
						const unsigned int len__
						)
					__attribute__((\
						always_inline, used, \
						visibility("hidden")));
// read :
extern char			__mem_read(\
						const unsigned char *restrict const mode__,
						void *src__,
						void *dest__,
						const unsigned int len__
						)
					__attribute__((\
						always_inline, used, \
						visibility("hidden")));
extern char			__mem_read_buffer(\
						const unsigned char spec__,
						void *src__,
						void *dest__,
						const unsigned int len__
						)
					__attribute__((\
						always_inline, used, \
						visibility("hidden")));
extern char			__mem_read_file(\
						void *src__,
						void *dest__,
						const unsigned int len__
						)
					__attribute__((\
						always_inline, used, \
						visibility("hidden")));
// copy :
extern char			__mem_copy(\
						const unsigned char *restrict const mode__,
						void *src__,
						void *dest__,
						const unsigned int len__
						)
					__attribute__((\
						always_inline, used, \
						visibility("hidden")));
extern char			__mem_copy_raw(\
						t_mem_alloc_ *src__,
						unsigned char *dest__,
						const unsigned int len__
						)
					__attribute__((\
						always_inline, used, \
						visibility("hidden")));
extern char			__mem_replace(\
						t_mem_alloc_ *src__,
						unsigned char *dest__,
						const unsigned int len__
						)
					__attribute__((\
						always_inline, used, \
						visibility("hidden")));
// shift :
extern unsigned int	__mem_shift(\
						const unsigned char *restrict const mode__,
						void *restrict const area__,
						char *restrict const val__
						)
					__attribute__((\
						always_inline, used, \
						visibility("hidden")));
extern unsigned int	__mem_shift_by(\
						const unsigned char spec__,
						unsigned char *restrict const area__,
						const unsigned int shift__,
						const unsigned int len__
						)
					__attribute__((\
						always_inline, used, \
						visibility("hidden")));
extern unsigned int	__mem_rewind(\
						const unsigned char *restrict const area__
						)
					__attribute__((\
						always_inline, used, \
						visibility("hidden")));
extern unsigned int	__mem_avoid_by(\
						const unsigned char target__,
						const unsigned char *restrict const area__,
						const unsigned char *restrict const end__
						)
					__attribute__((\
						always_inline, used, \
						visibility("hidden")));
// compare :
extern char			__mem_compare(\
						const char *const area__,
						const char *const target__,
						unsigned int *len__
						)
					__attribute__((\
						always_inline, used, \
						visibility("hidden")));
// search :
extern int			__mem_search(\
						const unsigned char *restrict const mode__,
						const void *restrict const area__,
						const void *restrict const target__
						)
					__attribute__((\
						always_inline, used, \
						visibility("hidden")));
extern int			__mem_search_data(\
						const char *const area__,
						const char *const target__
						)
					__attribute__((\
						always_inline, used, \
						visibility("hidden")));
extern int			__mem_search_keep(\
						const t_mem__ *restrict const mem__,
						const unsigned char spec__,
						const unsigned int size__
						)
					__attribute__((\
						always_inline, used, \
						visibility("hidden")));
extern int			__mem_search_file(\
						const char *restrict const target__
						)
					__attribute__((\
						always_inline, used, \
						visibility("hidden")));

#endif
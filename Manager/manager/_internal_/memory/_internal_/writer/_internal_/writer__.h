/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writer__.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/06/27 16:50:53 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRITER___H
# define WRITER___H

# pragma once

/* -------- modules --------- */
	// ----- local ----- //
# include "./types__.h"

	// ---- private ---- //
# include "../_private_/writer_.h"

/* ------- prototypes ------- */
	// --- internal ---- //
// init :
extern char			__writer_init(\
						t_writer_ *restrict const writer__
						)
					__attribute__((\
						always_inline, used, \
						visibility("hidden")));
// setup :
extern char			__writer_setup(\
						t_writer_ **writer__,
						const t_mem *restrict const mem__
						)
					__attribute__((\
						always_inline, used, \
						visibility("hidden")));
// write :
extern char			__writer_proc(\
						const unsigned int target__,
						const char *buffer__,
						const unsigned int len__
						)
					__attribute__((\
						always_inline, used, \
						visibility("hidden")));
#endif
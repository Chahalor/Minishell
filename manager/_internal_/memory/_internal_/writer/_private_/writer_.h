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

#ifndef WRITER__H
# define WRITER__H

# pragma once

/* -------- modules --------- */
	// --- internal ---- //
# include "../_internal_/writer__.h"

	// ----- local ----- //
# include "./types_.h"

/* ------- prototypes ------- */
	// ---- private ---- //
// init :
extern char			_writer_init(\
						t_writer_ *restrict const writer_
						)
					__attribute__((\
						always_inline, used, \
						visibility("hidden")));
// write :
extern char			_writer_proc(\
						const char *target_,
						const char *buffer_
						)
					__attribute__((\
						hot, used, \
						visibility("hidden")));
#endif
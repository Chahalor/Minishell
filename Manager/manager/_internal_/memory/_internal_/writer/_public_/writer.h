/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/06/19 13:39:48 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRITER_H
# define WRITER_H

# pragma once

/* -------- modules --------- */
	// --- internal ---- //
# include "../_internal_/writer__.h"

	// ----- local ----- //
# include "./types.h"

/* ------- prototypes ------- */
	// ---- public ----- //
// setup :
extern char writer_setup(\
				t_writer **writer,
				const t_mem *restrict const mem
				)
			__attribute__((\
				always_inline, used, \
				visibility("default")));

#endif
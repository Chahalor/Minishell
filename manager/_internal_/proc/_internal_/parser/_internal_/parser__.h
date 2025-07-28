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

#ifndef PARSER___H
# define PARSER___H

# pragma once

/* -------- modules --------- */
	// ---- locals ----- //
# include "./types__.h"

	// ---- private ---- //
# include "../_private_/parser_.h"

/* ------- prototypes ------- */
	// --- internal ---- //
// init :
extern char		__parse_init(\
					t_parse_ *restrict const parse__
					)
				__attribute__((\
					always_inline, used \
					visibility("hidden")));
// access :
extern t_parse_	*__parse_get(\
					t_parse_	*restrict const new__
					)
				__attribute__((\
					always_inline, used \
					visibility("hidden")));
extern t_parse_	*__parse_self(void)
				__attribute__((\
					always_inline, used \
					visibility("hidden")));
// parse :
extern char		__parse(\
					t_parse_ *restrict const parse__,
					const char *cmd__
					)
				__attribute__((\
					always_inline, used \
					visibility("hidden")));

#endif
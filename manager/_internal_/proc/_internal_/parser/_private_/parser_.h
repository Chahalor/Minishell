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

#ifndef PARSER__H
# define PARSER__H

# pragma once

/* -------- modules --------- */
	// --- internal ---- //
# include "../_internal_/parser__.h"

	// ---- locals ----- //
# include "./types_.h"

/* ------- prototypes ------- */
	// ---- private ---- //
// access :
extern t_parse_	*_parse_get(\
					t_parse_	*restrict const new_
					)
				__attribute__((\
					hot, used \
					visibility("hidden")));
extern t_parse_	*_parse_self(void)
				__attribute__((\
					hot, used \
					visibility("hidden")));
// parse :
extern char		_parse(\
					const char *cmd_
					)
				__attribute__((\
					hot, used \
					visibility("hidden")));

#endif
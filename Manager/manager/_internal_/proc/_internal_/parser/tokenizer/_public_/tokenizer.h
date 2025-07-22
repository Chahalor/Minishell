/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer__.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/06/25 14:35:34 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZER_H
# define TOKENIZER_H

# pragma once

/* -------- modules --------- */
	// --- internal ---- //
# include "../_internal_/tokenizer__.h"

	// ----- local ----- //
# include "./types.h"

/* ------- prototypes ------- */
	// ---- public ----- //
// init :
extern char	token_init(\
				t_token *restrict const token
				)
			__attribute__((\
				always_inline, used, \
				visibility("default")));

#endif
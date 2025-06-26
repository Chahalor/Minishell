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

#ifndef TOKENIZER___H
# define TOKENIZER___H

# pragma once

/* -------- modules --------- */
	// ----- local ----- //
# include "./types__.h"

	// ---- private ---- //
# include "../_private_/tokenizer_.h"

	// ---- global ----- //
# include "../../../../../../_public_/manager.h"

/* ------- prototypes ------- */
	// --- internal ---- //
// init :
extern char	__token_init(\
				t_token__ *restrict token__
				const t_mem *restrict const mem__,
				)
			__attribute__((\
				always_inline, used, \
				visibility("hidden")));
// methods :
// ...

#endif
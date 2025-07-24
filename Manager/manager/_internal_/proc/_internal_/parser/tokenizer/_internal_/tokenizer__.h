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

/* ------- prototypes ------- */
	// --- internal ---- //
// init :
extern char				__token_init(\
							t_token_ *restrict const token__
							)
						__attribute__((\
							always_inline, used, \
							visibility("hidden")));
// access :
extern t_token_			*__token_get(\
							t_token_	*restrict const new__
							)
						__attribute__((\
							always_inline, used, \
							visibility("hidden")));
extern t_token_			*__token_self(void)
						__attribute__((\
							always_inline, used, \
							visibility("hidden")));
// setup :
extern char				__token_setup(\
							t_token__ **token__,
							const t_mem *restrict const mem__,
							const char **argv__,
							const unsigned int argc__
							)
						__attribute__((\
							always_inline, used, \
							visibility("hidden")));
// parser :
extern void				__token_parse(\
							t_token_ *restrict const token__,
							const t_mem *restrict const mem__,
							const char **argv__,
							const unsigned int argc__
							)
						__attribute__((\
							always_inline, used, \
							visibility("hidden")));
// token :
extern char				__tokenize(\
							t_token_ **token__
							const t_mem *restrict const mem__,
							const char **argv__,
							const unsigned int argc__
							)
						__attribute__((\
							always_inline, used, \
							visibility("hidden")));
// fetch :
extern t_token_object_	*__token_fetch(\
							const t_token_ *restrict const token__,
							const unsigned char mode__
							)
						__attribute__((\
							always_inline, used, \
							visibility("hidden")));

#endif
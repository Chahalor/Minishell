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

#ifndef TOKENIZER__H
# define TOKENIZER__H

# pragma once

/* -------- modules --------- */
	// --- internal ---- //
# include "../_internal_/tokenizer__.h"

	// ----- local ----- //
# include "./types_.h"

/* ------- prototypes ------- */
	// ---- private ---- //
// access :
extern t_token_			*_token_get(\
							t_token_	*restrict const new_
							)
						__attribute__((\
							hot, used, \
							visibility("hidden")));
extern t_token_			*_token_self(void)
						__attribute__((\
							hot, used, \
							visibility("hidden")));
// remove :
extern void				_token_unload(void)
						__attribute__((\
							always_inline, used, \
							visibility("hidden")));
// setup :
extern char				_token_setup(\
							const char **argv_,
							const unsigned int argc_
							)
						__attribute__((\
							always_inline, used, \
							visibility("hidden")));
// parser :
extern void				_token_parse(\
							const char **argv_,
							const unsigned int argc_
							)
						__attribute__((\
							always_inline, used, \
							visibility("hidden")));
// token :
extern char				_tokenize(\
							const char **argv_,
							const unsigned int argc_
							)
						__attribute__((\
							hot, used, \
							visibility("hidden")));
// fetch :
extern t_token_object_	*_token_fetch(\
							const unsigned char mode_
							)
						__attribute__((\
							hot, used, \
							visibility("hidden")));

#endif
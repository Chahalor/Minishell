/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/05/29 12:56:39 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZER_H
# define TOKENIZER_H

# pragma once

/* -------- modules --------- */
	// --- internals --- //
# include "_internal_/_tokenizer.h"

	// ---- locals ----- //
# include "./types.h"

/* ------- prototypes ------- */
	// ---- hidden ----- //
// methods :
extern char	tokenize(\
				char *command
				)
			__attribute__((\
				hot, used, \
				visibility("hidden")));

	// ---- exposed ---- //
// init :
extern char	init_tokenizer(\
				t_tokenizer *restrict tokenizer
				)
			__attribute__((\
				cold, used, \
				visibility("default")));

#endif
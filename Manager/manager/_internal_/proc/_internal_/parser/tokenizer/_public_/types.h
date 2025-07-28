/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types_.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/06/25 14:26:54 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# undef TYPES_H
# pragma once

/* -------- modules --------- */
	// ---- access ----- //
# include "tokenizer.h"

/* --------- enums ---------- */
	// --- tokenizer --- //
# ifndef E_TOKEN
#  define E_TOKEN

// all public token module types.
enum e_token_type	// v.1. >>> tag: exp->e_token_type
{
	token_word		= token_word__,
	token_pipe		= token_pipe__,
	token_left		= token_left__,
	token_right		= token_right__,
	token_dleft		= token_dleft__,
	token_dright	= token_dright__,
	token_eof		= token_eof__,
};

// all public token module modes.
enum e_token_modes	// v.1. >>> tag: exp->e_token_modes
{
	token_actual	= token_actual__,
	token_next		= token_next__,
};

# endif

/* --------- types ---------- */
	// --- tokenizer --- //
# ifndef T_TOKEN
#  define T_TOKEN

// v.1. >>> tag: exp->t_token_object
typedef t_token_object__	t_token_object;
typedef struct s_token		t_token;	// v.1. >>> tag: exp->t_token

# endif

/* -------- structs --------- */
	// --- tokenizer --- //
# ifndef S_TOKEN
#  define S_TOKEN

// tokenizer public struct.
struct	s_token		// v.1. >>> tag: def->s_token
{
	// data :
	char			_internal_[sizeof(t_token__)];
	// >>>
	// access :
	char			(*tokenize)(\
								const char **, \
								const unsigned int);
	t_token_object	*(*fetch)(\
								const unsigned char);
};

# endif

#endif
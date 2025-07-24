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

#ifndef TYPES__H
# define TYPES__H

# undef TYPES__H
# pragma once

/* -------- modules --------- */
	// ---- access ----- //
# include "tokenizer_.h"

/* --------- enums ---------- */
	// --- tokenizer --- //
# ifndef E_TOKEN_
#  define E_TOKEN_

// all private token module types.
enum e_token_type_		// v.1. >>> tag: exp->e_token_type_
{
	token_word_		= token_word__,
	token_pipe_		= token_pipe__,
	token_left_		= token_left__,
	token_right_	= token_right__,
	token_dleft_	= token_dleft__,
	token_dright_	= token_dright__,
	token_eof_		= token_eof__,
};

// all private token module modes.
enum e_token_modes_		// v.1. >>> tag: exp->e_token_modes_
{
	token_actual_	= token_actual__,
	token_next_		= token_next__,
};

// all private token module error codes.
enum e_token_errors_	// v.1. >>> tag: exp->e_token_errors_
{
	// ...
};

# endif

/* --------- types ---------- */
	// --- tokenizer --- //
# ifndef T_TOKEN_
#  define T_TOKEN_

// v.1. >>> tag: exp->t_token_object_
typedef t_token_object__	t_token_object_;
typedef struct s_token_		t_token_;		// v.1. >>> tag: exp->t_token_

# endif

/* -------- structs --------- */
	// --- tokenizer --- //
# ifndef S_TOKEN_
#  define S_TOKEN_

// tokenizer private struct.
struct	s_token_		// v.1. >>> tag: exp->s_token_
{
	// data :
	char			_internal_[sizeof(t_token__)];
	// >>>
	// access :
	char			(*tokenize_)(\
								const char **, \
								const unsigned int);
	t_token_object_	*(*fetch_)(\
								const unsigned char);
};

# endif

/* ---------- size ---------- */
	// --- tokenizer --- //
# ifndef SZ_TOKEN_
#  define SZ_TOKEN_

// all private sizes used in token module.
enum e_token_sizes_	// v.1. >>> tag: exp->e_token_sizes_
{
	// sizes :
	token_object_size_		= token_object_size__,
	token_size_				= token_size__,
	// offsets :
	token_object_offset_	= token_object_offset__
};

# endif

#endif
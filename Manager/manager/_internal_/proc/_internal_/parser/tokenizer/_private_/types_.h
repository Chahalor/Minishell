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
	// ---- private ---- //
# include "tokenizer_.h"

/* --------- enums ---------- */
	// --- tokenizer --- //
# ifndef E_TOKEN_
#  define E_TOKEN_

// all private token module types.
enum e_token_type_	// v.1. >>> tag: exp->e_token_type_
{
	token_word_			= token_word__,
	token_pipe_			= token_pipe__,
	token_left_			= token_left__,
	token_right_		= token_right__,
	token_dleft_		= token_dleft__,
	token_dright_		= token_dright__,
	token_eof_			= token_eof__,
};

// all private token module error codes.
enum e_token_errors_	// v.1. >>> tag: exp->e_token_errors_
{
	none	// placeholder.
};

# endif

/* --------- types ---------- */
	// --- tokenizer --- //
# ifndef T_TOKEN_
#  define T_TOKEN_

// v.1. >>> tag: exp->t_token_type_
typedef enum e_token_type_		t_token_type_;
// v.1. >>> tag: exp->t_token_object_
typedef struct s_token_object_	t_token_object_;
typedef struct s_token_			t_token_;		// v.1. >>> tag: exp->t_token

# endif

/* -------- structs --------- */
	// --- tokenizer --- //
# ifndef S_TOKEN_
#  define S_TOKEN_

// tokenizer private struct.
struct	s_token_		// v.1. >>> tag: def->s_token
{
	// data :
	char			_internal_[sizeof(t_token__)];
	// >>>
	// access :
	char			(*tokenize_)(\
								const t_mem *restrict const mem_,
								const char **argv_,
								const unsigned int argc_);
};

# endif

/* ---------- size ---------- */
	// ---- memory ----- //
# ifndef SZ_TOKEN_
#  define SZ_TOKEN_

// all private sizes used in token module.
enum e_token_sizes__	// v.1. >>> tag: exp->e_token_sizes_
{
	// sizes :
	token_object_size_	= token_object_size__,
	token_size_			= token_size__,
	// offsets :
	// ...
};

# endif

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types__.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/06/25 15:02:32 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES___H
# define TYPES___H

# undef TYPES___H
# pragma once

/* -------- modules --------- */
	// --- externals --- //
# include "../../../../../../../standards/standards.h"

/* --------- enums ---------- */
	// --- tokenizer --- //
# ifndef E_TOKEN__
#  define E_TOKEN__

// all internal token module types.
enum e_token_type__	// v.1. >>> tag: set->e_token_type_
{
	token_word__	= +0,
	token_pipe__	= '|',
	token_left__	= '<',
	token_right__	= '>',
	token_dleft__	= '<' + '<',
	token_dright__	= '>' + '>',
	token_eof__		= +6,
};

// all internal token module error codes.
enum e_token_errors__	// v.1. >>> tag: set->e_token_errors_
{
	// ...
};

# endif

/* --------- types ---------- */
	// --- tokenizer --- //
# ifndef T_TOKEN__
#  define T_TOKEN__

// v.1. >>> tag: def->t_token_type_
typedef enum e_token_type__		t_token_type__;
// v.1. >>> tag: def->t_token_object_
typedef struct s_token_object__	t_token_object__;
typedef struct s_token__		t_token__;		// v.1. >>> tag: def->t_token

# endif

/* -------- structs --------- */
	// --- tokenizer --- //
# ifndef S_TOKEN__
#  define S_TOKEN__

// internal token object.
struct s_token_object__	// v.1. >>> tag: def->s_token_object_
{
	t_token_type__			type__;			// token type.
	char					*content__;		// token content.
};

// tokenizer internal struct.
struct	s_token__		// v.1. >>> tag: def->s_token
{
	unsigned int			size__;			// token list size.
	unsigned int			index__;
	t_token_object__		*content__;		// tokens list.
};

# endif

/* ---------- size ---------- */
	// --- tokenizer --- //
# ifndef SZ_TOKEN__
#  define SZ_TOKEN__

// all internal sizes used in token module.
enum e_token_sizes__	// v.1. >>> tag: set->e_token_sizes_
{
	// sizes :
	token_object_size__		= (\
								sizeof(t_token_object__)),
	token_size__			= (\
								sizeof(t_token__)),
	// offsets :
	token_object_offset__	= (0),
};

# endif

#endif
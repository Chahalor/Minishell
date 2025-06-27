/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types__.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/06/27 16:36:10 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES___H
# define TYPES___H

# undef TYPES___H
# pragma once

/* -------- modules --------- */
	// --- externals --- //
# include "../../../../../../standards/_public_/standards.h"

/* --------- enums ---------- */
	// ---- reader ----- //
# ifndef E_READER__
#  define E_READER__

// all internal reader modes for module methods.
enum e_mem_modes__	// v.1. >>> tag: set->e_mem_modes
{
	reader_container__		= +0,
	reader_file__			= +1,
};

// all internal reader module error codes.
enum e_reader_errors__	// v.1. >>> tag: set->e_reader_errors_
{
	reader_invalid_target__	= -7,
	reader_no_gate__		= -6,
	reader_not_registered__	= -5,
	reader_gate_burst__		= -4,
	reader_fatal_crash__	= -3,
	reader_line_end__		= -2,
	reader_file_end__		= -1,
};

# endif

/* --------- types ---------- */
	// ---- reader ----- //
# ifndef T_READER__
#  define T_READER__

// v.1. >>> tag: def->t_container_
typedef struct s_container__	t_container__;
typedef struct s_reader__		t_reader__;		// v.1. >>> tag: def->t_reader

# endif

/* -------- structs --------- */
	// ---- reader ----- //
# ifndef S_READER__
#  define S_READER__

// internal reader container for file.
struct s_container__	// v.1. >>> def: def->s_container_
{
	unsigned int	target__;
	unsigned int	size__;
	unsigned int	len__;
	char			*buffer__;
	t_container__	*gate__;
};
// internal reader management access struct.
struct s_reader__		// v.1. >>> def: def->s_reader
{
	unsigned int	size__;
	unsigned int	qty__;
	t_container__	*gate__;
};

# endif

/* ---------- size ---------- */
	// ---- reader ----- //
# ifndef SZ_READER__
#  define SZ_READER__

// all internal sizes used in reader module.
enum e_reader_sizes__	// v.1. >>> tag: set->e_reader_sizes
{
	// sizes :
	reader_container_size__	= (\
								sizeof(t_container__)),
	reader_size__			= (\
								sizeof(t_reader__)),
};

# endif

#endif
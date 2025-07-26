/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types_.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/06/27 16:42:53 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# undef TYPES_H
# pragma once

/* -------- modules --------- */
	// ----- local ----- //
# include "reader.h"

/* --------- enums ---------- */
	// ---- reader ----- //
# ifndef E_READER
#  define E_READER

// all public reader modes for module methods.
enum e_reader_modes			// v.1. >>> tag: exp->e_reader_modes
{
	reader_container		= reader_container__,
	reader_fd				= reader_fd__,
	reader_file				= reader_file__,
	reader_bin				= reader_bin__,
};

// all public reader files modes for module methods.
enum e_reader_files_modes	// v.1. >>> tag: exp->e_reader_files_modes
{
	reader_read				= reader_read__,
	reader_write			= reader_write__,
	reader_read_write		= reader_read_write__,
	reader_append			= reader_append__,
};


# endif

/* --------- types ---------- */
	// ---- reader ----- //
# ifndef T_READER
#  define T_READER

typedef struct s_reader		t_reader;		// v.1. >>> tag: exp->t_reader

# endif

/* -------- structs --------- */
	// ---- reader ----- //
# ifndef S_READER
#  define S_READER

// public reader management access struct.
struct s_reader		// v.1. >>> def:  exp->s_reader
{
	// data :
	char		_internal_[sizeof(t_reader__)];
	// >>>
	// access :
	char		(*find)(\
						const unsigned char *restrict const, \
						const char *, \
						void **);
	char		(*add)(\
						const unsigned int, \
						void **);
	char		(*read)(\
						const int, \
						char **);
};

# endif

#endif
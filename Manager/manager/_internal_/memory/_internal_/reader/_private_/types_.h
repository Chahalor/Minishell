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

#ifndef TYPES__H
# define TYPES__H

# undef TYPES__H
# pragma once

/* -------- modules --------- */
	// ----- local ----- //
# include "reader_.h"

/* --------- enums ---------- */
	// ---- reader ----- //
# ifndef E_READER_
#  define E_READER_

// all private reader modes for module methods.
enum e_reader_modes_		// v.1. >>> tag: exp->e_reader_modes_
{
	reader_container_		= reader_container__,
	reader_fd_				= reader_fd__,
	reader_file_			= reader_file__,
	reader_bin_				= reader_bin__,
	reader_all_				= reader_all__,
};

// all private reader files modes for module methods.
enum e_reader_files_modes_	// v.1. >>> tag: exp->e_reader_files_modes_
{
	reader_read_			= reader_read__,
	reader_write_			= reader_write__,
	reader_read_write_		= reader_read_write__,
	reader_append_			= reader_append__,
};

// all private reader module error codes.
enum e_reader_errors_		// v.1. >>> tag: exp->e_reader_errors_
{
	reader_invalid_target_	= reader_invalid_target__,
	reader_failed_opening_	= reader_failed_opening__,
	reader_no_support_		= reader_no_support__,
	reader_no_gate_			= reader_no_gate__,
	reader_not_registered_	= reader_not_registered__,
	reader_gate_burst_		= reader_gate_burst__,
	reader_fatal_crash_		= reader_fatal_crash__,
	reader_line_end_		= reader_line_end__,
	reader_file_end_		= reader_file_end__,
};

# endif

/* --------- types ---------- */
	// ---- reader ----- //
# ifndef T_READER_
#  define T_READER_

typedef t_container__		t_container_;	// v.1. >>> tag: exp->t_container_
typedef struct s_reader_	t_reader_;		// v.1. >>> tag: exp->t_reader_
// v.1. >>> tag: exp->t_reader_find_func_
typedef char 				(*t_reader_find_func_)(\
								const unsigned char *restrict const,
								const char *restrict const,
								void **);
// v.1. >>> tag: exp->t_reader_find_container_func_
typedef char 				(*t_reader_find_container_func_)(\
								const char *restrict const,
								void **);
typedef char				(*t_reader_remove_func_)(\
								const char *restrict const);

# endif

/* -------- structs --------- */
	// ---- reader ----- //
# ifndef S_READER_
#  define S_READER_

// private reader management access struct.
struct s_reader_		// v.1. >>> def:  exp->s_reader_
{
	// data :
	char		_internal_[sizeof(t_reader__)];
	// >>>
	// access :
	char		(*find_)(\
						const unsigned char *restrict const, \
						const char *, \
						void **);
	char		(*add_)(\
						const unsigned int, \
						void **);
	char		(*remove_)(\
						const unsigned char *restrict const,
						const char *restrict const);
	char		(*read_)(\
						const int, \
						char **);
};

# endif

#endif
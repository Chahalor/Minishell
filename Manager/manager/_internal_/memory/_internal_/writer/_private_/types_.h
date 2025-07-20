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

#ifndef TYPES__H
# define TYPES__H

# undef TYPES__H
# pragma once

/* -------- modules --------- */
	// ----- local ----- //
# include "writer_.h"

/* --------- enums ---------- */
	// ---- writer ----- //
# ifndef E_WRITER_
#  define E_WRITER_

// all private writer module error codes.
enum e_writer_errors_	// v.1. >>> tag: exp->e_writer_errors_
{
	writer_invalid_target_	= writer_invalid_target__,
	writer_failed_			= writer_failed__,
};

# endif

/* --------- types ---------- */
	// ---- writer ----- //
# ifndef T_WRITER_
#  define T_WRITER_

typedef struct s_writer_		t_writer_;		// v.1. >>> tag: exp->t_writer_

# endif

/* -------- structs --------- */
	// ---- writer ----- //
# ifndef S_WRITER_
#  define S_WRITER_

// private writer management access struct.
struct s_writer_		// v.1. >>> def: exp->s_writer_
{
	// access :
	char		(*write_)(\
						const char *, \
						const char *);
};

# endif

#endif
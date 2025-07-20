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
# include "writer.h"

/* --------- types ---------- */
	// ---- writer ----- //
# ifndef T_WRITER
#  define T_WRITER

typedef struct s_writer		t_writer;		// v.1. >>> tag: exp->t_writer

# endif

/* -------- structs --------- */
	// ---- writer ----- //
# ifndef S_WRITER
#  define S_WRITER

// public writer management access struct.
struct s_writer		// v.1. >>> def: exp->s_writer
{
	// access :
	char		(*write)(\
						const char *, \
						const char *);
};

# endif

#endif
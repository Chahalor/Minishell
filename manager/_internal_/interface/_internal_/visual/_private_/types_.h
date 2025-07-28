/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types__.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/06/27 14:36:33 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES__H
# define TYPES__H

# undef TYPES__H
# pragma once

/* -------- modules --------- */
	// ----- local ----- //
# include "visual_.h"

/* --------- enums ---------- */
	// ---- visual ----- //
# ifndef E_VISUAL_
#  define E_VISUAL_

// all private visual module error codes.
enum e_visual_errors_	// v.1. >>> tag: exp->e_visual_errors_
{
	visual_writing_failure_	= visual_writing_failure__,
};

# endif

/* --------- types ---------- */
	// ---- visual ----- //
# ifndef T_VISUAL_
#  define T_VISUAL_

typedef struct s_visual_	t_visual_;	// v.1. >>> tag: exp->t_visual_

# endif

/* -------- structs --------- */
	// ---- visual ----- //
# ifndef S_VISUAL_
#  define S_VISUAL_

// private struct of visual module.
struct s_visual_	// v.1. >>> tag: exp->s_visual_
{
	// data :
	char	_internal_[sizeof(t_visual__)];
	// >>>
	// access :
	int		(*printf_)(\
						const char *const restrict, \
						...);
	int		(*rprintf_)(\
						const char *const restrict, \
						...);
	int		(*fprintf_)(\
						const int, \
						const char *const restrict, \
						...);
	int		(*sprintf_)(\
						char *const restrict, \
						const char *const restrict, \
						...);
	int		(*perror_)(\
						const char *const restrict, \
						...);
};

# endif

#endif
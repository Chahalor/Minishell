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

#ifndef TYPES_H
# define TYPES_H

# undef TYPES_H
# pragma once

/* -------- modules --------- */
	// ----- local ----- //
# include "visual.h"

/* --------- types ---------- */
	// ---- visual ----- //
# ifndef T_VISUAL
#  define T_VISUAL

typedef struct s_visual	t_visual;	// v.1. >>> tag: exp->t_visual

# endif

/* -------- structs --------- */
	// ---- visual ----- //
# ifndef S_VISUAL
#  define S_VISUAL

// public struct of visual module.
struct s_visual	// v.1. >>> tag: exp->s_visual
{
	// data :
	char	_internal_[sizeof(t_visual__)];
	// >>>
	// access :
	int		(*printf)(\
					const char *const restrict, \
					...);
	int		(*rprintf)(\
					const char *const restrict, \
					...);
	int		(*fprintf)(\
					const int, \
					const char *const restrict, \
					...);
	int		(*sprintf)(\
					char *const restrict, \
					const char *const restrict, \
					...);
	int		(*perror)(\
					const char *const restrict, \
					...);
};

# endif

#endif
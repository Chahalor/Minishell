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
# include "proc.h"

/* --------- types ---------- */
	// ----- proc ------ //
# ifndef T_PROC
#  define T_PROC

typedef struct s_proc	t_proc;	// v.1. >>> tag: exp->t_proc

# endif

/* -------- structs --------- */
	// ----- proc ------ //
# ifndef S_PROC
#  define S_PROC

// public struct of proc module.
struct s_proc	// v.1. >>> tag: exp->s_proc
{
	// data :
	t_exec	exec;
	t_parse	parse;
	// >>>
	// access :
	// ...
};

# endif

#endif
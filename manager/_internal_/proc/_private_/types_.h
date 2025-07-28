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
# include "proc_.h"

/* --------- types ---------- */
	// ----- proc ------ //
# ifndef T_PROC_
#  define T_PROC_

typedef struct s_proc_	t_proc_;	// v.1. >>> tag: exp->t_proc_

# endif

/* -------- structs --------- */
	// ----- proc ------ //
# ifndef S_PROC_
#  define S_PROC_

// private struct of proc module.
struct s_proc_	// v.1. >>> tag: exp->s_proc_
{
	// data :
	t_exec	exec_;
	t_parse	parse_;
	// >>>
	// access :
	// ...
};

# endif

#endif
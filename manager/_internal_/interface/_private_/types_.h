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
# include "interface_.h"

/* --------- types ---------- */
	// --- interface --- //
# ifndef T_INTERFACE_
#  define T_INTERFACE_

// v.1. >>> tag: exp->t_interface_
typedef struct s_interface_	t_interface_;

# endif

/* -------- structs --------- */
	// --- interface --- //
# ifndef S_INTERFACE_
#  define S_INTERFACE_

// private struct of interface module.
struct s_interface_	// v.1. >>> tag: exp->s_interface_
{
	// data :
	t_server			server_;
	t_interraction		interraction_;
	t_visual			visual_;
	// >>>
	// access :
	// ...
};

# endif

#endif
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

#ifndef TYPES___H
# define TYPES___H

# undef TYPES___H
# pragma once

/* -------- modules --------- */
	// --- externals --- //
# include "../../../../standards/_public_/standards.h"

/* --------- types ---------- */
	// --- interface --- //
# ifndef T_INTERFACE__
#  define T_INTERFACE__

// v.1. >>> tag: def->t_interface
typedef struct s_interface__	t_interface__;

# endif

/* -------- structs --------- */
	// --- interface --- //
# ifndef S_INTERFACE__
#  define S_INTERFACE__

// internal struct of interface module.
struct s_interface__	// v.1. >>> tag: def->s_interface
{
	// data :
	t_server			server__;
	t_interraction		interraction__;
	t_visual			visual__;
	// >>>
	// access :
	// ...
};

# endif

#endif
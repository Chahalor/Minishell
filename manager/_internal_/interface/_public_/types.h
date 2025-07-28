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
# include "interface.h"

/* --------- types ---------- */
	// --- interface --- //
# ifndef T_INTERFACE
#  define T_INTERFACE

// v.1. >>> tag: exp->t_interface
typedef struct s_interface	t_interface;

# endif

/* -------- structs --------- */
	// --- interface --- //
# ifndef S_INTERFACE
#  define S_INTERFACE

// public struct of interface module.
struct s_interface	// v.1. >>> tag: exp->s_interface
{
	// data :
	t_server			server;
	t_interraction		interraction;
	t_visual			visual;
	// >>>
	// access :
	// ...
};

# endif

#endif
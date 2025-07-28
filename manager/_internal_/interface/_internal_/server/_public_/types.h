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
# include "server.h"

/* --------- types ---------- */
	// ---- server ----- //
# ifndef T_SERVER
#  define T_SERVER

typedef t_signal__			t_signal;	// v.1. >>> tag: exp->t_signal
typedef struct s_server		t_server;	// v.1. >>> tag: exp->t_server

# endif

/* -------- structs --------- */
	// ---- server ----- //
# ifndef S_SERVER
#  define S_SERVER

// public struct of server module.
struct s_server	// v.1. >>> tag: exp->s_server
{
	// data :
	t_signal	sigint;
	t_signal	sigquit;
	t_signal	sigstp;
	// >>>
	// access :
	char		(*reset)(void);
};

# endif

#endif
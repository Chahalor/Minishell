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
# include "server_.h"

/* --------- types ---------- */
	// ---- server ----- //
# ifndef T_SERVER_
#  define T_SERVER_

typedef t_signal__			t_signal_;	// v.1. >>> tag: exp->t_signal_
typedef t_infos__			t_infos_;	// v.1. >>> tag: exp->t_infos_
typedef struct s_server_	t_server_;	// v.1. >>> tag: exp->t_server_

# endif

/* -------- structs --------- */
	// ---- server ----- //
# ifndef S_SERVER_
#  define S_SERVER_

// private struct of server module.
struct s_server_	// v.1. >>> tag: exp->s_server_
{
	// data :
	t_signal_	sigint_;
	t_signal_	sigquit_;
	t_signal_	sigstp_;
	// >>>
	// access :
	char		(*reset_)(void);
};

# endif

#endif
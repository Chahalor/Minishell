/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _types.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/06/12 16:01:29 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES__H
# define TYPES__H

# undef TYPES__H
# pragma once

/* -------- modules --------- */
	// ----- local ----- //
# include "history_.h"

/* --------- types ---------- */
	// ---- history ---- //
# ifndef T_HISTORY_
#  define T_HISTORY_

typedef struct s_histo_	t_histo_;	// v.1. >>> tag: exp->t_histo_

# endif

/* -------- structs --------- */
	// ---- history ---- //
# ifndef S_HISTORY_
#  define S_HISTORY_

struct s_histo_		// v.1. >>> tag: exp->s_histo_
{
	// data :
	char		_internal_[sizeof(t_histo__)];
	// >>>
	// access :
	char		(*load_)(void);
	char		(*unload_)(void);
	char		(*add_)(\
						const char *restrict const);
	char		(*find_)(\
						const unsigned int);
	char		(*show_)(void);
};

# endif

#endif
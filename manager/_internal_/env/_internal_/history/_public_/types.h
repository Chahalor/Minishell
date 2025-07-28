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

#ifndef TYPES_H
# define TYPES_H

# undef TYPES_H
# pragma once

/* -------- modules --------- */
	// ----- local ----- //
# include "history.h"

/* --------- types ---------- */
	// ---- history ---- //
# ifndef T_HISTORY
#  define T_HISTORY

typedef struct s_histo	t_histo;	// v.1. >>> tag: exp->t_histo

# endif

/* -------- structs --------- */
	// ---- history ---- //
# ifndef S_HISTORY
#  define S_HISTORY

struct s_histo	// v.1. >>> tag: exp->s_histo
{
	// data :
	char		_internal_[sizeof(t_histo__)];
	// >>>
	// access :
	char		(*load)(void);
	char		(*unload)(void);
	char		(*add)(\
						const char *restrict const);
	char		(*find)(\
						const unsigned int);
	char		(*show)(void);
};

# endif

#endif
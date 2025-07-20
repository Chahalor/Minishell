/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _types.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/05/27 10:16:16 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# undef TYPES_H
# pragma once

/* -------- modules --------- */
	// ----- local ----- //
# include "state.h"

/* --------- types ---------- */
	// ----- state ----- //
# ifndef T_STATE
#  define T_STATE

typedef struct s_state	t_state;	// v.1. >>> tag: exp->t_state

# endif

/* -------- structs --------- */
	// ----- state ----- //
# ifndef S_STATE
#  define S_STATE

// public state of the shell.
struct s_state		// v.1. >>> tag: exp->s_state
{
	// data :
	char	_internal_[sizeof(t_state__)];
	// >>>
	// access :
	void	(*chuser)(\
					const char *restrict const);
	void	(*chdir)(\
					const char *restrict const);
	char	*(*user)(void);
	char	*(*dir)(void);
};

# endif

#endif
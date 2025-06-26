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

#ifndef _TYPES_H
# define _TYPES_H

# undef _TYPES_H
# pragma once

/* -------- modules --------- */
	// --- externals --- //
# include "../../../../standards/standards.h"

/* --------- types ---------- */
	// ----- state ----- //
# ifndef _T_STATE
#  define _T_STATE

typedef struct s_state_		t_state_;	// v.1. >>> tag: set->t_state

# endif

/* -------- structs --------- */
	// ----- state ----- //
# ifndef _S_STATE
#  define _S_STATE

// state of the shell.
struct s_state_		// v.1. >>> tag: set->s_state
{
	char					*user;		// username.
	char					*dir;		// current working directory.
	// >>>
	char					(*chuser)(\
									const char *restrict const);
	char					(*chdir)(\
									const char *restrict const);
	char					*(*gtuser)(void);
	char					*(*gtdir)(void);
};

# endif

#endif
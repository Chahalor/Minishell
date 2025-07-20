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

#ifndef TYPES__H
# define TYPES__H

# undef TYPES__H
# pragma once

/* -------- modules --------- */
	// ----- local ----- //
# include "state_.h"

/* --------- types ---------- */
	// ----- state ----- //
# ifndef T_STATE_
#  define T_STATE_

typedef struct s_state_	t_state_;	// v.1. >>> tag: exp->t_state_

# endif

/* -------- structs --------- */
	// ----- state ----- //
# ifndef S_STATE_
#  define S_STATE_

// private state of the shell.
struct s_state_		// v.1. >>> tag: exp->s_state_
{
	// data :
	char	_internal_[sizeof(t_state__)];
	// >>>
	// access :
	void	(*chuser_)(\
					const char *restrict const);
	void	(*chdir_)(\
					const char *restrict const);
	char	*(*user_)(void);
	char	*(*dir_)(void);
};

# endif

#endif
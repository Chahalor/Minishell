/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _types.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/05/26 12:33:48 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES__H
# define TYPES__H

# undef TYPES__H
# pragma once

/* -------- modules --------- */
	// ----- local ----- //
# include "env_.h"

/* --------- types ---------- */
	// ------ env ------ //
# ifndef T_ENV_
#  define T_ENV_

typedef struct s_env_	t_env_;		// v.1. >>> tag: exp->t_env_

# endif

/* -------- structs --------- */
	// ------ env ------ //
# ifndef S_ENV_
#  define S_ENV_

// private env of the shell.
struct s_env_		// v.1. >>> tag: exp->s_env_
{
	// data :
	char		_internal_[sizeof(t_env__)];
	t_state		state_;
	t_histo		histo_;
	// >>>
	// access :
	char		(*chhome_)(\
						const char *restrict const);
	char		(*chpath_)(\
						const char *restrict const);
	char		*(home_)(void);
	char		*(path_)(void);
	char		*(vars_)(void);
	char		*(find_)(\
						const char *restrict const);
	char		(*set_)(\
						const char *restrict const, \
						const char *restrict const);
	char		(*unset_)(\
						const char *restrict const);
};

# endif

#endif
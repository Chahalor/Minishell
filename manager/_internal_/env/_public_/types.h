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

#ifndef TYPES_H
# define TYPES_H

# undef TYPES_H
# pragma once

/* -------- modules --------- */
	// ----- local ----- //
# include "env.h"

/* --------- types ---------- */
	// ------ env ------ //
# ifndef T_ENV
#  define T_ENV

typedef struct s_env	t_env;		// v.1. >>> tag: exp->t_env

# endif

/* -------- structs --------- */
	// ------ env ------ //
# ifndef S_ENV
#  define S_ENV

// public env of the shell.
struct s_env_		// v.1. >>> tag: exp->s_env
{
	// data :
	char		_internal_[sizeof(t_env__)];
	t_state		state;
	t_histo		histo;
	// >>>
	// access :
	char		(*chhome)(\
						const char *restrict const);
	char		(*chpath)(\
						const char *restrict const);
	char		*(home)(void);
	char		*(path)(void);
	char		*(vars)(void);
	char		*(find)(\
						const char *restrict const);
	char		(*set)(\
						const char *restrict const, \
						const char *restrict const);
	char		(*unset)(\
						const char *restrict const);
};

# endif

#endif
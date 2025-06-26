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

#ifndef _TYPES_H
# define _TYPES_H

# undef _TYPES_H
# pragma once

/* -------- modules --------- */
	// --- externals --- //
# include "../../../../standards/standards.h"

/* --------- enums ---------- */
	// ------ env ------ //
# ifndef _E_ENV
#  define _E_ENV

// search types.
enum e_types_
{
	_var,
	_file
};

# endif

/* --------- types ---------- */
	// ------ env ------ //
# ifndef _T_ENV
#  define _T_ENV

typedef struct s_env_		t_env_;		// v.1. >>> tag: set->t_env

# endif

/* -------- structs --------- */
	// ------ env ------ //
# ifndef _S_ENV
#  define _S_ENV

// env of the shell.
struct s_env_		// v.1. >>> tag: set->s_env
{
	unsigned int			fd;			// fd of the shell env file.
	unsigned int			qty;		// qty of vars in the env.
	unsigned int			size;		// size of the env (in bytes).
	char					*home;		// home directory for '~'.
	char					*path;		// path value of the env.
										// this path represents
										// only valid binary paths.
	char					**content;	// env. content (variables).
	// >>>
	char					(*load)(void);
	char					*(*gthome)(void);
	char					*(*gtpath)(void);
	char					(*set)(\
									const char *restrict const);
	char					(*unset)(\
									const char *restrict const);
	// >>>
	char					*(*find)(\
									const unsigned char, \
									const char *restrict const);
};

# endif

#endif
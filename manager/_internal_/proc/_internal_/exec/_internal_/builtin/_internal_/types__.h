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

#ifndef TYPES___H
# define TYPES___H

# undef TYPES___H
# pragma once

/* -------- modules --------- */
	// --- externals --- //
# include "../../../../../../../../standards/_public_/standards.h"

/* --------- enums ---------- */
	// ---- builtin ---- //
# ifndef E_BUILTIN__
#  define E_BUILTIN__

// all internal builtin module error codes.
enum e_builtin_errors__	// v.1. >>> tag: def->e_builtin_errors_
{
	builtin_fork_failure__		= -4,
	builtin_too_many_args__		= -3,
	builtin_invalid_target__	= -2,
	builtin_invalid_value__		= -1,
};

# endif

/* --------- types ---------- */
	// ---- builtin ---- //
# ifndef T_BUILTIN__
#  define T_BUILTIN__

// v.1. >>> tag: def->t_builtin_cd_
typedef struct s_builtin_cd__		t_builtin_cd__;
// v.1. >>> tag: def->t_builtin_call_
typedef struct s_builtin_call__		t_builtin_call__;
// v.1. >>> tag: def->t_builtin
typedef struct s_builtin__			t_builtin__;

# endif

/* -------- structs --------- */
	// ---- builtin ---- //
# ifndef S_BUILTIN__
#  define S_BUILTIN__

// internal cd representation of builtin module.
struct s_builtin_cd__	// v.1. >>> tag: def->s_builtin_cd_
{
	char			error__;
	unsigned char	help__;
	unsigned char	pwd__;
	unsigned char	home__;
};

// internal call representation of builtin module.
struct s_builtin_call__	// v.1. >>> tag: def->s_builtin_call_
{
	const char	*name__;
	char		(*func__)(\
						const char **, \
						const int, \
						const int);
};

// internal struct of builtin module.
struct s_builtin__		// v.1. >>> tag: def->s_builtin
{
	// ...
};

# endif

#endif
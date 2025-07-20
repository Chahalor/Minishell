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

#ifndef TYPES___H
# define TYPES___H

# undef TYPES___H
# pragma once

/* -------- modules --------- */
	// --- externals --- //
# include "../../../../standards/standards.h"

/* --------- types ---------- */
	// ------ env ------ //
# ifndef T_ENV__
#  define T_ENV__

typedef struct s_env__	t_env__;		// v.1. >>> tag: def->t_env

# endif

/* -------- structs --------- */
	// ------ env ------ //
# ifndef S_ENV__
#  define S_ENV__

// internal env of the shell.
struct s_env__		// v.1. >>> tag: def->s_env
{
	unsigned int	size__;			// size of the env (in vars).
	unsigned int	qty__;			// qty of vars in the env.
	char			*home__;		// home directory for '~'.
	char			*path__;		// path value of the env.
	char			**content__;	// env. content (variables).
};

# endif

#endif
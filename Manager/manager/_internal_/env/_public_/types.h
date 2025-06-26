/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/05/23 14:45:21 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# undef TYPES_H
# pragma once

/* -------- modules --------- */
	// --- internals --- //
# include "_internal_/_types.h"

/* --------- types ---------- */
	// ------ env ------ //
# ifndef T_ENV
#  define T_ENV

typedef t_env_	t_env;

# endif

/* -------- structs --------- */
	// ------ env ------ //
# ifndef S_ENV
#  define S_ENV

// env of the shell.
struct s_env_	s_env;

# endif

#endif
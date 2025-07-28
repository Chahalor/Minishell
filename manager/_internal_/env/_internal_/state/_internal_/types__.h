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

#ifndef TYPES___H
# define TYPES___H

# undef TYPES___H
# pragma once

/* -------- modules --------- */
	// --- externals --- //
# include "../../../../standards/standards.h"

/* --------- types ---------- */
	// ----- state ----- //
# ifndef T_STATE__
#  define T_STATE__

typedef struct s_state__	t_state__;	// v.1. >>> tag: def->t_state

# endif

/* -------- structs --------- */
	// ----- state ----- //
# ifndef S_STATE__
#  define S_STATE__

// internal state of the shell.
struct s_state__		// v.1. >>> tag: def->s_state
{
	char	*user;		// username.
	char	*dir;		// current working directory.
};

# endif

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/05/23 13:30:26 by rcreuzea         ###   ########.fr       */
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
	// ----- state ----- //
# ifndef T_STATE
#  define T_STATE

typedef t_state_	t_state;

# endif

/* -------- structs --------- */
	// ----- state ----- //
# ifndef S_STATE
#  define S_STATE

struct s_state_		s_state;

# endif

#endif
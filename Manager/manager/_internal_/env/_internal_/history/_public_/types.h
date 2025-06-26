/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/06/12 16:02:18 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# undef TYPES_H
# pragma once

/* -------- modules --------- */
	// --- internals --- //
# include "./history.h"

/* --------- types ---------- */
	// ---- history ---- //
# ifndef T_HISTORY
#  define T_HISTORY

typedef struct s_histo		t_histo;

# endif

/* -------- structs --------- */
	// ---- history ---- //
# ifndef S_HISTORY
#  define S_HISTORY

struct s_histo
{
	// data :
	unsigned char	_internal_[_history_size];
	// >>>
	// access :
	char			(*load)(void);
	void			(*unload)(void);
	char			(*show)(void);
	char			(*add)(\
							const char *restrict const);
	char			(*get)(\
							const unsigned int);
};

# endif

#endif
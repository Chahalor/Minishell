/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _types.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/06/12 16:01:29 by rcreuzea         ###   ########.fr       */
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
	// ---- history ---- //
# ifndef T_HISTORY__
#  define T_HISTORY__

typedef struct s_histo__	t_histo__;	// v.1. >>> tag: def->t_histo

# endif

/* -------- structs --------- */
	// ---- history ---- //
# ifndef S_HISTORY__
#  define S_HISTORY__

struct s_histo__		// v.1. >>> tag: def->s_histo
{
	unsigned int			size;		// total size of the history (cmds).
	unsigned int			head;		// head index of the ring buffer.
	unsigned int			tail;		// tail index of the ring buffer.
	char					*content[HISTORY_SIZE];	// history content (cmds).
	/*
	 * The history content has an overall size (in cmd(s)) of HISTORY_SIZE.
	*/
};

# endif

#endif
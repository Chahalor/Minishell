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

#ifndef _TYPES_H
# define _TYPES_H

# undef _TYPES_H
# pragma once

/* -------- modules --------- */
	// --- externals --- //
# include "../../../../standards/standards.h"

/* --------- types ---------- */
	// ---- history ---- //
# ifndef _T_HISTORY
#  define _T_HISTORY

typedef struct s_histo_		t_histo_;	// v.1. >>> tag: set->t_histo

# endif

/* -------- structs --------- */
	// ---- history ---- //
# ifndef _S_HISTORY
#  define _S_HISTORY

struct s_histo_		// v.1. >>> tag: set->s_histo
{
	unsigned int			fd;			// fd of the shell history file.
	unsigned int			size;		// total size of the history (in cmd).
	unsigned int			head;		// head index of the ring buffer.
	unsigned int			tail;		// tail index of the ring buffer.
	char					*path;		// path of the history.
	/*
	 * If only a name is stored inside the path,
	 * we'll consider ~/ as default base path.
	*/
	char					**content;	// history content (line by lines).
	/*
	 * The history content has an overall size (in cmd(s)) of HISTORY_SIZE.
	*/
};

# endif

#endif
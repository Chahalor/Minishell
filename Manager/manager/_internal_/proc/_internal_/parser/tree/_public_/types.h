/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/05/29 13:12:25 by rcreuzea         ###   ########.fr       */
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
	// ----- tree ------ //
# ifndef T_TREE
#  define T_TREE

typedef t_tree_	t_tree;

# endif

/* -------- structs --------- */
	// ----- tree ------ //
# ifndef S_TREE
#  define S_TREE

struct s_tree_	s_tree;

# endif

#endif
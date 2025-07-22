/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _types.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/06/02 14:41:48 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES__H
# define TYPES__H

# undef TYPES__H
# pragma once

/* -------- modules --------- */
	// ---- access ----- //
# include "tree_.h"

/* --------- enums ---------- */
	// ----- tree ------ //
# ifndef E_TREE_
#  define E_TREE_

// private redir types of tree module.
enum e_tree_redir_type_		// v.1. >>> tag: exp->e_tree_redir_type_
{
	tree_in_		= tree_in__,
	tree_out_		= tree_out__,
	tree_add_		= tree_add__,
	tree_air_		= tree_air__,
};

// private nodes types of tree module.
enum e_tree_node_type_		// v.1. >>> tag: exp->e_tree_redir_type_
{
	tree_cmd_		= tree_cmd__,
	tree_pipe_		= tree_pipe__,
};

# endif

/* --------- types ---------- */
	// ----- tree ------ //
# ifndef T_TREE_
#  define T_TREE_

// v.1. >>> tag: exp->t_tree_redir_type_
typedef enum e_tree_redir_type_	t_tree_redir_type_;
// v.1. >>> tag: exp->t_tree_node_type_
typedef enum e_tree_node_		t_tree_node_type_;
// v.1. >>> tag: exp->t_tree_redir_
typedef t_tree_redir__			t_tree_redir_;
// v.1. >>> tag: exp->t_tree_cmd_
typedef t_tree_cmd__			t_tree_cmd_;
// v.1. >>> tag: exp->t_tree_
typedef t_tree__				t_tree_;

# endif

/* ---------- size ---------- */
	// ----- tree ------ //
# ifndef SZ_TREE_
#  define SZ_TREE_

// all private sizes used in tree module.
enum e_tree_sizes_	// v.1. >>> tag: exp->e_tree_sizes_
{
	// sizes :
	tree_redir_size_	= tree_redir_size__,
	tree_cmd_size_		= tree_cmd_size__,
	tree_size_			= tree_size__,
};

# endif


#endif
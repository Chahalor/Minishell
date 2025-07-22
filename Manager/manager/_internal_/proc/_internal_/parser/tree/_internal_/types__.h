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

#ifndef TYPES___H
# define TYPES___H

# undef TYPES___H
# pragma once

/* -------- modules --------- */
	// --- externals --- //
# include "../../../../../../standards/standards.h"

/* --------- enums ---------- */
	// ----- tree ------ //
# ifndef E_TREE__
#  define E_TREE__

// internal redir types of tree module.
enum e_tree_redir_type__		// v.1. >>> tag: def->e_tree_redir_type
{
	tree_in__		= +0,	// input.
	tree_out__		= +1,	// output.
	tree_add__		= +2,	// append.
	tree_air__		= +3,	// air doc.
};

// internal nodes types of tree module.
enum e_tree_node_type__		// v.1. >>> tag: def->e_tree_redir_type
{
	tree_cmd__		= +0,	// command.
	tree_pipe__		= +1,	// pipe.
};

# endif

/* --------- types ---------- */
	// ----- tree ------ //
# ifndef T_TREE__
#  define T_TREE__

// v.1. >>> tag: def->t_tree_redir_type
typedef enum e_tree_redir_type__	t_tree_redir_type__;
// v.1. >>> tag: def->t_tree_node_type
typedef enum e_tree_node__			t_tree_node_type__;
// v.1. >>> tag: def->t_tree_redir
typedef struct s_tree_redir__		t_tree_redir__;
// v.1. >>> tag: def->t_tree_cmd
typedef struct s_tree_cmd__			t_tree_cmd__;
// v.1. >>> tag: def->t_tree
typedef struct s_tree__				t_tree__;

# endif

/* -------- structs --------- */
	// ----- tree ------ //
# ifndef S_TREE__
#  define S_TREE__

// internal redirection representation struct.
struct s_tree_redir__	// v.1. >>> tag: def->s_tree_redir
{
	t_tree_redir_type__	type__;		// redir type.
	char				*target__;	// target, either limiter or file.
	t_tree_redir__		*next__;	// >>>
};
// internal command representation struct.
struct s_tree_cmd__		// v.1. >>> tag: def->s_tree_cmd
{
	unsigned char		builtin__;	// if we'll need to find the binary.
	char				*target__;	// cmd name.
	char				**args__;	// cmd args.
	t_tree_redir__		*redir__;	// all related redirects.
};
// internal tree rooting struct.
struct s_tree__			// v.1. >>> tag: def->s_tree
{
	t_tree_node_type__	type__;		// tree section type.
	union
	{
		t_tree_cmd__	cmd__;		// command.
		struct
		{
			t_tree__	*left__;	// left tree section of the pipe.
			t_tree__	*right__;	// right tree section of the pipe.
		}				pipe__;		// pipe.
	}					content__;	// >>>
};

# endif

/* ---------- size ---------- */
	// ----- tree ------ //
# ifndef SZ_TREE__
#  define SZ_TREE__

// all internal sizes used in tree module.
enum e_tree_sizes__	// v.1. >>> tag: set->e_tree_sizes_
{
	// sizes :
	tree_redir_size__	= (\
							sizeof(t_tree_redir__)),
	tree_cmd_size__		= (\
							sizeof(t_tree_cmd__)),
	tree_size__			= (\
							sizeof(t_tree__)),
};

# endif

#endif
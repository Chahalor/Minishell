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

#ifndef TYPES_H
# define TYPES_H

# undef TYPES_H
# pragma once

/* -------- modules --------- */
	// ---- access ----- //
# include "tree.h"

/* --------- enums ---------- */
	// ----- tree ------ //
# ifndef E_TREE
#  define E_TREE

// internal redir types of tree module.
enum e_tree_redir_type		// v.1. >>> tag: exp->e_tree_redir_type
{
	tree_in			= tree_in__,
	tree_out		= tree_out__,
	tree_add		= tree_add__,
	tree_air		= tree_air__,
};

// internal nodes types of tree module.
enum e_tree_node_type		// v.1. >>> tag: exp->e_tree_redir_type
{
	tree_cmd		= tree_cmd__,
	tree_pipe		= tree_pipe__,
};

# endif

/* --------- types ---------- */
	// ----- tree ------ //
# ifndef T_TREE
#  define T_TREE

// v.1. >>> tag: exp->t_tree_redir_type
typedef enum e_tree_redir_type		t_tree_redir_type;
// v.1. >>> tag: exp->t_tree_node_type
typedef enum e_tree_node			t_tree_node_type;
// v.1. >>> tag: exp->t_tree_redir
typedef struct s_tree_redir			t_tree_redir;
// v.1. >>> tag: exp->t_tree_cmd
typedef struct s_tree_cmd			t_tree_cmd;
// v.1. >>> tag: exp->t_tree_pipe
typedef struct s_tree_pipe			t_tree_pipe;
// v.1. >>> tag: exp->t_tree
typedef struct s_tree				t_tree;

# endif

/* -------- structs --------- */
	// ----- tree ------ //
# ifndef S_TREE
#  define S_TREE

// public redirection representation struct.
struct s_tree_redir	// v.1. >>> tag: exp->s_tree_redir
{
	t_tree_redir_type	type;
	char				*target;
	t_tree_redir		*next;
};
// public command representation struct.
struct s_tree_cmd	// v.1. >>> tag: exp->s_tree_cmd
{
	unsigned char		builtin;
	char				*target;
	char				**args;
	t_tree_redir		*redir;
};
// public pipe representation struct.
struct s_tree_pipe	// v.1. >>> tag: exp->s_tree_pipe
{
	t_tree				*left;
	t_tree				*right;
}
// public tree rooting struct.
struct s_tree		// v.1. >>> tag: exp->s_tree
{
	t_tree_node_type	type;
	union
	{
		t_tree_cmd		cmd;
		t_tree_pipe		pipe;
	}					content;
};

# endif

#endif
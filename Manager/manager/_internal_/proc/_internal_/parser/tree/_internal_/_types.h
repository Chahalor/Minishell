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

#ifndef _TYPES_H
# define _TYPES_H

# undef _TYPES_H
# pragma once

/* -------- modules --------- */
	// --- externals --- //
# include "../../../../../../standards/standards.h"

/* --------- enums ---------- */
	// ----- tree ------ //
# ifndef _E_TREE
#  define _E_TREE

enum e_redir_
{
	_in		= 0,	// input.
	_out,			// output.
	_add,			// append.
	_air,			// air doc.
};

enum e_node_
{
	_cmd	= 0,	// command.
	_pipe,			// pipe.
};

# endif

/* --------- types ---------- */
	// ----- tree ------ //
# ifndef _T_TREE
#  define _T_TREE

typedef struct s_redir_	t_redir_;	// v.1. >>> tag: set->t_redir
typedef struct s_cmd_	t_cmd_;		// v.1. >>> tag: set->t_cmd
typedef struct s_tree_	t_tree_;	// v.1. >>> tag: set->t_tree

# endif

/* -------- structs --------- */
	// ----- tree ------ //
# ifndef _S_TREE
#  define _S_TREE

// redirection representation struct.
struct s_redir_	// v.1. >>> tag: set->s_redir
{
	unsigned char	_type;		// redir type.
	char			*_target;	// target, either limiter or file.
	t_redir_		*_next;		// >>>
};
// command representation struct.
struct s_cmd_	// v.1. >>> tag: set->s_cmd
{
	unsigned char	_builtin;	// if we'll need to find the binary.
	unsigned int	_size;		// capacity of args.
	unsigned int	_len;		// effective qty of args.
	char			*_name;		// cmd name.
	char			**_args;	// cmd args.
	t_redir_		*redir;		// all related redirects.
};
// tree rooting struct.
struct s_tree_	// v.1. >>> tag: set->s_tree
{
	unsigned char	_type;		// tree section type.
	union
	{
		t_cmd_		_cmd;		// unique command.
		struct
		{
			t_tree_	*_left;		// left tree section of the pipe.
			t_tree_	*_right;	// right tree section of the pipe.
		}			_pipe;		// pipe link.
	}				_content;	// >>>
};

# endif

#endif
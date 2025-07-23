/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init__.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/06/25 14:39:07 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ADD__C
# define ADD__C

/* -------- modules --------- */
	// ---- access ----- //
# include "tree_.h"

/* -------- inlines --------- */

// doc ...
__attribute__((always_inline, used))
//	(-private-)
extern inline char	_tree_cmd(\
	t_tree **cmd_,
	const unsigned int size_
)	// v.1. >>> tag: exp->_tree_cmd
{
	return (__tree_cmd((t_mem *)&_manager()->mem, \
						cmd_, size_));
}

// doc ...
__attribute__((always_inline, used))
//	(-private-)
extern inline t_tree_	*_tree_pipe(\
	const t_tree_ *const left_,
	const t_tree_ *const right_
)	// v.1. >>> tag: exp->_tree_pipe
{
	return (__tree_pipe((t_mem *)&_manager()->mem, \
						left_, right_));
}

// doc ...
__attribute__((always_inline, used))
//	(-private-)
extern inline char	_tree_redir(\
	t_tree *restrict const cmd_,
	const t_tree_redir_type__ type_,
	const char *restrict const target_
)	// v.1. >>> tag: exp->_tree_redir
{
	return (__tree_pipe((t_mem *)&_manager()->mem, \
						cmd_, type_, target_));
}

#endif
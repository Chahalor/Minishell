/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _tree.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/06/02 15:31:09 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _TREE_C
# define _TREE_C

/* -------- modules --------- */
	// ---- access ----- //
# include "_tree.h"

/* -------- inlines --------- */

// doc ...
__attribute__((always_inline, used))
// (-hidden-)
extern inline char	_create(\
	t_tree_ **restrict tree,
	const unsigned char type
)	// v.1. >>> tag: def->create
{
	if (unexpect(\
			alloc(\
				(void **)tree, \
				sizeof(t_tree_)) \
			!= no_error))
		return (failed_to_allocate);
	(*tree)->_type = type;
	return (no_error);
}

// doc ...
__attribute__((always_inline, used))
// (-hidden-) x (-local-)
extern inline char	_redir(\
	t_tree_ *restrict tree,
	t_redir_ **redir
)	// v.1. >>> .
{
	
	return (no_error);
}

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access__.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/06/27 10:37:24 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACCESS___C
# define ACCESS___C

/* -------- modules --------- */
	// ---- access ----- //
# include "tree__.h"

/* -------- inlines --------- */

// doc ...
__attribute__((always_inline, used))
// (-internal-)
extern inline t_tree_	*__tree_get(\
	t_tree_	*restrict const new__
)	// v.1. >>> tag: def->_tree_get
{
	static t_tree_	*restrict	tree__ = NULL;

	if (unexpect(!tree__ && new__))
		tree__ = new__;
	return (tree__);
}

// doc ...
__attribute__((always_inline, used))
// (-internal-)
extern inline t_tree_	*__tree_self(void)	// v.1. >>> tag: def->_tree_self
{
	return (_tree_get(NULL));
}

#endif
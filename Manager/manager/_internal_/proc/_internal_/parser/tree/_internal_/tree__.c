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

#ifndef TREE___C
# define TREE___C

/* -------- modules --------- */
	// ---- access ----- //
# include "tree__.h"

/* -------- inlines --------- */

// doc ...
__attribute__((always_inline, used))
//	(-internal-)
extern inline char	__tree(\
	const t_token *restrict const token__
)	// v.1. >>> tag: def->tree
{
	t_tree_	*base__;
	t_tree_	*tree__;

	base__ = _tree_self();
	_tree_unload();
	tree__ = _tree_parse(token__);
	if (unexpect(!tree__ \
			|| !_tree_get(tree__) \
			|| _tree_self() == base__))
		return (failed_to_setup);
	return (no_error);
}

#endif
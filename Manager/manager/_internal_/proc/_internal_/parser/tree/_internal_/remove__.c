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

#ifndef REMOVE___C
# define REMOVE___C

/* -------- modules --------- */
	// ---- access ----- //
# include "tree__.h"

/* -------- inlines --------- */

// doc ...
__attribute__((always_inline, used))
//	(-internal-)
extern inline char	*__tree_unload_redir(\
	t_mem *restrict const mem__,
	t_tree_redir_ *redir__
)	// v.1. >>> tag: def->_tree_unload_redir
{
	t_tree_redir_	*temp__;

	while (redir__)
	{
		temp__ = redir__->next__;
		mem__->clean((unsigned char [1]){mem_ptr}, none, \
					redir__, tree_redir_size__);
		redir__ = temp__;
	}
}

// doc ...
__attribute__((always_inline, used))
//	(-internal-)
extern inline void	__tree_unload(\
	t_tree_ *tree__,
	t_mem *restrict const mem__
)	// v.1. >>> tag: def->_tree_unload
{
	if (tree__->type__ == tree_pipe_)
	{
		_tree_unload(tree__->pipe__.left__);
		_tree_unload(tree__->pipe__.right__);
	}
	else
		_tree_unload_redir(tree__->content__.cmd__.redir__);
	mem__->clean((unsigned char [1]){mem_ptr}, none, tree__, tree_size__);
}

#endif
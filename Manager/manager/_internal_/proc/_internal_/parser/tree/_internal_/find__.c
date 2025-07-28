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

#ifndef FIND___C
# define FIND___C

/* -------- modules --------- */
	// ---- access ----- //
# include "tree__.h"

/* -------- inlines --------- */

// doc ...
__attribute__((always_inline, used))
//	(-internal-)
extern inline t_tree_redir_	**__find_last_redir(\
	t_tree *restrict const cmd__
)	// v.1. >>> tag: def->_find_last_redir
{
	t_tree_redir_	**redir__;

	redir__ = &cmd__->content__->cmd__.redir__;
	while (*redir__)
		redir__ = &(*redir__)->next__;
	return (redir__);
}

#endif
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

#ifndef REMOVE__C
# define REMOVE__C

/* -------- modules --------- */
	// ---- access ----- //
# include "tree_.h"

/* ------- functions -------- */

// doc ...
__attribute__((hot, used))
//	(-private-)
extern char	*_tree_unload_redir(\
	t_tree_redir_ *redir_
)	// v.1. >>> tag: exp->_tree_unload_redir
{
	return (__tree_unload_redir((t_mem *)&_manager->mem, \
								redir_));
}

// doc ...
__attribute__((hot, used))
//	(-private-)
extern void	_tree_unload(void)	// v.1. >>> tag: exp->_tree_unload
{
	return (__tree_unload(_tree_self(), (t_mem *)&_manager->mem));
}

#endif
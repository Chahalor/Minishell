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

#ifndef BUILTIN__C
# define BUILTIN__C

/* -------- modules --------- */
	// ---- access ----- //
# include "tree_.h"

/* -------- inlines --------- */

// doc ...
__attribute__((always_inline, used))
//	(-private-)
extern inline char	_tree_builtin(\
	const char *restrict const target_
)	// v.1. >>> tag: exp->_tree_builtin
{
	return (__tree_buitin((t_mem *)&_manager()->mem, target_));
}

#endif
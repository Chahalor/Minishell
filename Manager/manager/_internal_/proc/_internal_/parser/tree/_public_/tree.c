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

#ifndef TREE_C
# define TREE_C

/* -------- modules --------- */
	// ---- access ----- //
# include "tree.h"

/* ------- functions -------- */

// doc ...
__attribute__((hot, used))
//	(-public-)
extern char	tree(\
	const t_token *restrict const token
)	// v.1. >>> tag: exp->tree
{
	return (__tree(token));
}

#endif
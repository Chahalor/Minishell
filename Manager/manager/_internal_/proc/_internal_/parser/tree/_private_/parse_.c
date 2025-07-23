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

#ifndef PARSE__C
# define PARSE__C

/* -------- modules --------- */
	// ---- access ----- //
# include "tree_.h"

/* ------- functions -------- */

// doc ...
__attribute__((hot, used))
//	(-private-)
extern char	_tree_parse_redir(\
	t_tree_ *restrict const cmd_,
	const t_token_object *token_
)	// v.1. >>> tag: exp->_tree_parse_redir
{
	return (__tree_parse_redir((t_mem *)&_manager->mem, \
								cmd_, token_));
}

// doc ...
__attribute__((hot, used))
//	(-private-)
extern t_tree_	*_tree_parse_cmd(\
	const t_token_object *token_
)	// v.1. >>> tag: exp->_tree_parse_cmd
{
	return (__tree_parse_cmd((t_mem *)&_manager->mem, \
							token_));
}

// doc ...
__attribute__((hot, used))
//	(-private-)
extern t_tree_	*_tree_parse(\
	const t_token_object *token_
)	// v.1. >>> tag: exp->_tree_parse
{
	return (__tree_parse(token_));
}

#endif
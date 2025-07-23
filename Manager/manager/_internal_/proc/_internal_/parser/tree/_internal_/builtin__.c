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

#ifndef BUILTIN___C
# define BUILTIN___C

/* -------- modules --------- */
	// ---- access ----- //
# include "tree__.h"

/* -------- inlines --------- */

// doc ...
__attribute__((always_inline, used))
//	(-internal-)
extern inline char	__tree_builtin(\
	t_mem *restrict const mem__,
	const char *restrict const target__
)	// v.1. >>> tag: def->_tree_builtin
{
	char					*builtins__[8] = {\
											"cd", "exit", "env", \
											"pwd", "echo", "export", \
											"unset", "history"};
	unsigned int			size__;
	register unsigned int	i__;

	size__ = mem__->size((unsigned char [1]){mem_len}, target__, 0);
	i__ = 0;
	while (i__ != 8)
		if (unexpect(mem__->compare(target__, builtins__[i__++], &size__)))
			return (TRUE);
	return (FALSE);
}

#endif
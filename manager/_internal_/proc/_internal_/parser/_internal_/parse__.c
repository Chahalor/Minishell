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

#ifndef PARSE___C
# define PARSE___C

/* -------- modules --------- */
	// ---- access ----- //
# include "parse__.h"

/* -------- inlines --------- */

// doc ...
__attribute__((always_inline, used))
//	(-internal-)
extern inline char	__parse(\
	t_parse_ *restrict const parse__,
	const char *cmd__
)	// v.1. >>> tag: def->_parse
{
	char			**argv__;
	unsigned int	argc__;

	if (unexpect(\
		(parse__->token__.tokenize(argv__, cmd__) != no_error)
		|| (tree(&parse__->token__) != no_error)))
		return (error);
	return (no_error);
}

#endif
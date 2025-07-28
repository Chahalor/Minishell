/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init__.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/06/25 15:06:11 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_C
# define INIT_C

/* -------- modules --------- */
	// ---- access ----- //
# include "parser.h"

/* -------- inlines --------- */

// doc ...
__attribute__((always_inline, used))
// (-public-)
extern inline char	parse_init(\
	t_parse *restrict const parse
)	// v.1. >>> tag: exp->parse_init
{
	return (__parse_init((t_parse_ *)parse));
}

#endif
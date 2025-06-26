/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expect.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/06/20 10:14:13 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPECT_C
# define EXPECT_C

/* -------- modules --------- */
	// ---- access ----- //
# include "wrappers.h"

/* -------- inlines --------- */

// doc ...
__attribute__((always_inline, used))
//	(-public-)
extern inline unsigned char	unexpect(\
	const unsigned char cond
)	// v.1. >>> exp: def->unexpect
{
	return (_unexpect(cond));
}

// doc ...
__attribute__((always_inline, used))
//	(-public-)
extern inline unsigned char	expect(\
	const unsigned char cond
)	// v.1. >>> tag: exp->expect
{
	return (_expect(cond));
}

#endif
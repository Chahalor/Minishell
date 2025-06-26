/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _expect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/05/15 12:25:26 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _EXPECT_C
# define _EXPECT_C

/* -------- modules --------- */
	// ---- access ----- //
# include "_wrappers.h"

/* -------- inlines --------- */

// doc ...
__attribute__((always_inline, used))
//	(-hidden-)
extern inline unsigned char	_unexpect(\
	const unsigned char cond
)	// v.1. >>> tag: def->unexpect
{
	return (__builtin_expect(cond, UNEXPECTED));
}

// doc ...
__attribute__((always_inline, used))
//	(-hidden-)
extern inline unsigned char	_expect(\
	const unsigned char cond
)	// v.1. >>> tag: def->expect
{
	return (__builtin_expect(cond, EXPECTED));
}

#endif
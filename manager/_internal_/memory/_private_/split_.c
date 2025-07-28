/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift__.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/06/27 14:20:12 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPLIT__C
# define SPLIT__C

/* -------- modules --------- */
	// ---- access ----- //
# include "memory_.h"

/* ------- functions -------- */

// doc ...
__attribute__((hot, used))
// (-private-)
extern char	**_mem_split(\
	const void *area_,
	const char sep_
)	// v.1. >>> tag: exp->_mem_split
{
	return (__mem_split((char *)area_, sep_));
}

#endif
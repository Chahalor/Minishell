/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/06/20 10:52:32 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MANAGE__C
# define MANAGE__C

/* -------- modules --------- */
	// ---- access ----- //
# include "memory_.h"

/* ------- functions -------- */

// doc ...
__attribute__((hot, used))
//	(-private-)
extern int	_mem_manage(\
	const unsigned char *restrict const mode_,
	void *area_,
	const unsigned int size_
)	// v.1. >>> .
{
	t_mem__	*mem__;

	mem__ = (t_mem__ *)_mem_self()->_internal_;
	if (unexpect(!mem__))
		return (0);
	return (__mem_manage(mem__, mode_, area_, size_));
}

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Delta_0ne <romain.creuzeau.pro@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/07/21 12:46:17 by Delta_0ne        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOAD__C
# define LOAD__C

/* -------- modules --------- */
	// ---- access ----- //
# include "history_.h"

/* ------- functions -------- */

// doc ...
__attribute__((cold, used))
//	(-private-)
extern char	_histo_load(void)	// v.1. >>> tag: exp->_histo_load
{
	return (__histo_load((t_histo__ *)&_histo_self()->_internal_, \
						(t_mem *)&_manager()->mem));
}

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read__.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/06/27 16:49:54 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRITE___C
# define WRITE___C

/* -------- modules --------- */
	// ---- access ----- //
# include "writer__.h"

/* -------- inlines --------- */

// doc ...
__attribute__((always_inline, used))
//	(-internal-)
extern inline char	__writer_proc(\
	const unsigned int target__,
	const char *buffer__,
	const unsigned int len__
)	// v.1. >>> tag: def->_writer_proc
{
	if (unexpect(write(target__, buffer__, len__) != len__))
		return (writer_failed_);
	return (no_error);
}

#endif
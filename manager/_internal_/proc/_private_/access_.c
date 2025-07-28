/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access__.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/06/20 13:46:54 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACCESS__C
# define ACCESS__C

/* -------- modules --------- */
	// ---- access ----- //
# include "proc_.h"

/* ------- functions -------- */

// doc ...
__attribute__((hot, used))
// (-private-)
extern t_proc_	*_proc_get(\
	t_proc_	*restrict const new_
)	// v.1. >>> tag: exp->_proc_get
{
	return (__proc_get(new_));
}

// doc ...
__attribute__((hot, used))
// (-private-)
extern t_proc_	*_proc_self(void)	// v.1. >>> tag: exp->_proc_self
{
	return (__proc_self());
}

#endif
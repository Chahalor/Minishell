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
# include "exec_.h"

/* ------- functions -------- */

// doc ...
__attribute__((hot, used))
// (-private-)
extern t_exec_	*_exec_get(\
	t_exec_	*restrict const new_
)	// v.1. >>> tag: exp->_exec_get
{
	return (__exec_get(new_));
}

// doc ...
__attribute__((hot, used))
// (-private-)
extern t_exec_	*_exec_self(void)	// v.1. >>> tag: exp->_exec_self
{
	return (__exec_self());
}

#endif
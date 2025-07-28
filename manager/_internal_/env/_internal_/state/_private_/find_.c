/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _state.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/05/27 10:16:07 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIND__C
# define FIND__C

/* -------- modules --------- */
	// ---- access ----- //
# include "state_.h"

/* ------- functions -------- */

// doc ...
__attribute__((hot, used))
//	(-private-)
extern char	*_state_gtuser(void)	// v.1. >>> tag: exp->_state_gtuser
{
	return (__state_gtuser((t_state_ *)&_state_self()->_internal_));
}

// doc ...
__attribute__((hot, used))
//	(-private-)
extern char	*_state_gtdir(void)	// v.1. >>> tag: exp->_state_gtdir
{
	return (__state_gtdir((t_state_ *)&_state_self()->_internal_));
}

#endif
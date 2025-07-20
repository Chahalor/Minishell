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

#ifndef CHANGE__C
# define CHANGE__C

/* -------- modules --------- */
	// ---- access ----- //
# include "state_.h"

/* ------- functions -------- */

// doc ...
__attribute__((cold, used))
//	(-private-)
extern void	_state_chuser(\
	const char *restrict const name_
)	// v.1. >>> tag: exp->_state_chuser
{
	return (__state_chuser((t_state_ *)&_state_self()->_internal_, name_));
}

// doc ...
__attribute__((hot, used))
//	(-private-)
extern void	_state_chdir(\
	const char *restrict const dir_
)	// v.1. >>> tag: exp->_state_chdir
{
	return (__state_chdir((t_state_ *)&_state_self()->_internal_, dir_));
}

#endif
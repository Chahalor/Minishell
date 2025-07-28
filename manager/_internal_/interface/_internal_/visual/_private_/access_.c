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
# include "visual_.h"

/* ------- functions -------- */

// doc ...
__attribute__((hot, used))
// (-private-)
extern t_visual_	*_visual_get(\
	t_visual_	*restrict const new_
)	// v.1. >>> tag: exp->_visual_get
{
	return (__visual_get(new_));
}

// doc ...
__attribute__((hot, used))
// (-private-)
extern t_visual_	*_visual_self(void)
// v.1. >>> tag: exp->_visual_self
{
	return (__visual_self());
}

#endif
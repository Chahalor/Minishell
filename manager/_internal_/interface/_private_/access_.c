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
# include "interface_.h"

/* ------- functions -------- */

// doc ...
__attribute__((hot, used))
// (-private-)
extern t_interface_	*_interface_get(\
	t_interface_	*restrict const new_
)	// v.1. >>> tag: exp->_interface_get
{
	return (__interface_get(new_));
}

// doc ...
__attribute__((hot, used))
// (-private-)
extern t_interface_	*_interface_self(void)
// v.1. >>> tag: exp->_interface_self
{
	return (__interface_self());
}

#endif
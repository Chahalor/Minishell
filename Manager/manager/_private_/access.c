/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/05/20 15:41:54 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACCESS_C
# define ACCESS_C

/* -------- modules --------- */
	// ---- access ----- //
# include "manager.h"

/* ------- functions -------- */

__attribute__((hot, used))
//	(-public-)
extern t_manager	*get_manager(\
	t_manager	*restrict const new
)	// v.1. >>> tag: exp->get_manager
{
	return (_get_manager(new));
}

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _setup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/05/22 12:22:45 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETUP_C
# define SETUP_C

/* -------- modules --------- */
	// ---- access ----- //
# include "manager.h"

/* -------- inlines --------- */

// doc ...
__attribute__((always_inline, used))
//	(-public-)
extern inline t_manager	*manager_setup(\
	char **env
)	// v.1. >>> tag: exp->manager_setup
{
	return (__manager_setup(env));
}

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/05/23 14:07:35 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETUP_C
# define SETUP_C

/* -------- modules --------- */
	// ---- access ----- //
# include "manager.h"

/* ------- functions -------- */

// doc ...
__attribute__((cold, used, malloc))
//	(-public-)
extern t_manager	*setup_manager(\
	char *restrict *restrict const env
)	// v.1. >>> tag: exp->setup_manager
{
	return (_setup_manager(env));
}

#endif
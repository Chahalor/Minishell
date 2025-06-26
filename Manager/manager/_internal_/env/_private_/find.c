/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/05/26 12:38:08 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIND_C
# define FIND_C

/* -------- modules --------- */
	// ---- access ----- //
# include "env.h"

/* ------- functions -------- */

// doc ...
__attribute__((hot, used))
//	(-public-)
extern char	*find(\
	const unsigned char type,
	const char *restrict const target
)	// v.1. >>> tag: exp->find
{
	t_manager_	*restrict	manager;

	manager = get_manager(NULL);
	return (_find(\
				(const t_state_ *restrict const)&manager->state, \
				(const t_env_ *restrict const)&manager->env, \
				type, target));
}

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _env.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/05/26 12:53:13 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ADD__C
# define ADD__C

/* -------- modules --------- */
	// ---- access ----- //
# include "env_.h"

/* ------- functions -------- */

// doc ...
__attribute__((hot, used))
//	(-private-)
extern char _env_set(\
	const char *restrict const target_,
	const char *restrict const content_
)	// v.1. >>> tag: exp->_env_set
{
	return (__env_set((t_env__ *)&_env_self()->_internal_, \
					(t_mem *)&_manager->mem, \
					target_, content_));
}

#endif
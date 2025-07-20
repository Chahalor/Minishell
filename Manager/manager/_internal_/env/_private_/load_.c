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

#ifndef LOAD__C
# define LOAD__C

/* -------- modules --------- */
	// ---- access ----- //
# include "env_.h"

/* ------- functions -------- */

// doc ...
__attribute__((cold, used))
//	(-private-)
extern char _env_chhome(\
	const char *restrict const new_
)	// v.1. >>> tag: exp->_env_chhome
{
	return (__env_chhome((t_env__ *)&_env_self()->_internal_), \
						(t_mem *)&_manager->mem, \
						new_);
}

// doc ...
__attribute__((cold, used))
//	(-private-)
extern char _env_chpath(\
	const char *restrict const new_
)	// v.1. >>> tag: exp->_env_chpath
{
	return (__env_chpath((t_env__ *)&_env_self()->_internal_, \
						(t_mem *)&_manager->mem, \
						new_));
}

#endif
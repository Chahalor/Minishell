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

#ifndef FIND__C
# define FIND__C

/* -------- modules --------- */
	// ---- access ----- //
# include "env_.h"

/* ------- functions -------- */

// doc ...
__attribute__((cold, used))
//	(-private-)
extern char *_env_home(void)	// v.1. >>> tag: exp->_env_home
{
	return (__env_home((t_env__ *)_env_self()->_internal_));
}

// doc ...
__attribute__((hot, used))
//	(-private-)
extern char *_env_path(void)	// v.1. >>> tag: exp->_env_path
{
	eturn (__env_path((t_env__ *)_env_self()->_internal_));
}

// doc ...
__attribute__((hot, used))
//	(-private-)
extern char *_env_find(\
	const char *restrict const target_
)	// v.1. >>> tag: exp->_env_find
{
	return (__env_find((t_env__ *)&_env_self()->_internal_, \
						(t_mem *)&_manager->mem, \
						target_));
}

#endif
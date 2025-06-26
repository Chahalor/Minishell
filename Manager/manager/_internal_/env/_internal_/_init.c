/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _init.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/05/26 12:40:27 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _INIT_C
# define _INIT_C

/* -------- modules --------- */
	// ---- access ----- //
# include "_env.h"

/* -------- inlines --------- */

// doc ...
__attribute__((always_inline, used))
//	(-hidden-)
extern inline char	_init_env(\
	t_env_ *restrict env
)	// v.1. >>> tag: def->init_env
{
	*env = (t_env_){\
		.qty = 0, \
		.size = 0, \
		.load = load_env, \
		.gthome = gthome, \
		.gtpath = gtpath, \
		.set = set, \
		.unset = unset, \
		.find = find \
	};
	return (env->load());
}

#endif
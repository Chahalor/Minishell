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

#ifndef INIT___C
# define INIT___C

/* -------- modules --------- */
	// ---- access ----- //
# include "env__.h"

/* -------- inlines --------- */

// doc ...
__attribute__((always_inline, used))
//	(-internal-)
extern inline char	__env_init(\
	t_env_ *restrict const env__
)	// v.1. >>> tag: def->env_init
{
	*env__ = (t_env_){\
		.chhome = _env_chhome, \
		.chpath = _env_chpath, \
		.home = _env_home, \
		.path = _env_path, \
		.find = _env_find, \
		.set = _env_set, \
		.unset = _env_unset, \
	};
	if (unexpect(!_env_get(env__)))
		return (failed_to_setup);
	return (_env_load());
}

#endif
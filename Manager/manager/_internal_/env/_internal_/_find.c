/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _find.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/05/26 12:37:42 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FIND_C
# define _FIND_C

/* -------- modules --------- */
	// ---- access ----- //
# include "_env.h"

/* -------- inlines --------- */

// doc ...
__attribute__((always_inline, used))
//	(-hidden-)
static inline char	*_find_var(\
	const t_env *restrict const env,
	const char *restrict const target
)	// v.1. >>> .
{
	char					*result;
	register unsigned int	i;

	i = 0;
	while (i != env->qty)
	{
		result = search(env->content[i++], target);
		if (unexpect(result != NULL))
			return (result);
	}
	return (NULL);
}

// doc ...
__attribute__((always_inline, used))
//	(-hidden-)
static inline char	*_find_file(\
	const t_state *restrict const state,
	const t_env *restrict const env,
	const char *restrict const target
)	// v.1. >>> .
{
	
}

// doc ...
__attribute__((always_inline, used))
//	(-hidden-)
extern inline char	*_find(\
	const t_state *restrict const state,
	const t_env *restrict const env,
	const unsigned char type,
	const char *restrict const target
)	// v.1. >>> tag: def->find
{
	if (type == _var)
		return (_find_var(env, target));
	else
		return (_find_file(state, env, target));
}

#endif
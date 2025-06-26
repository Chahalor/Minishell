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

#ifndef _ENV_C
# define _ENV_C

/* -------- modules --------- */
	// ---- access ----- //
# include "_env.h"

/* -------- inlines --------- */

// doc ...
__attribute__((always_inline, used))
//	(-hidden-)
extern inline char _load_env(\
	t_env_ *restrict const env
)	// v.1. >>> tag: def->load_env
{
	if (unexpect(open(env->path, &env->fd) != no_error))
		return (failed_to_open);
	while (TRUE)
		if (unexpect(\
				read(env->fd, \
					&env->content[env->qty++]) \
						!= no_error))
			break ;
	return (no_error);
}

// doc ...
__attribute__((always_inline, used))
//	(-hidden-)
extern inline char *_gthome(\
	t_env_ *restrict const env
)	// v.1. >>> tag: def->gthome
{
	return (env->path = env->find(_var, "HOME="));
}

// doc ...
__attribute__((always_inline, used))
//	(-hidden-)
extern inline char *_gtpath(\
	t_env_ *restrict const env
)	// v.1. >>> tag: def->gtpath
{
	return (env->path = env->find(_var, "PATH="));
}

// doc ...
__attribute__((always_inline, used))
//	(-hidden-)
extern inline char _set(\
	t_env_ *restrict const env,
	const char *restrict const var
)	// v.1. >>> tag: def->set
{
	// here we shall write the new var inside the env file.
	// here we shall realloc the content list and we shall
	// allocate an area to store the var.
}

// doc ...
__attribute__((always_inline, used))
//	(-hidden-)
extern inline char _unset(\
	t_env_ *restrict const env,
	const char *restrict const var
)	// v.1. >>> tag: def->unset
{
	// here we shall remove the var inside the env file.
	// here we shall realloc the content list and we shall
	// free the area of the var.
}


#endif
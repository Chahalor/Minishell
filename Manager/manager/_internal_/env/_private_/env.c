/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/05/23 15:01:04 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_C
# define ENV_C

/* -------- modules --------- */
	// ---- access ----- //
# include "env.h"

/* ------- functions -------- */

// doc ...
__attribute__((cold, used))
//	(-public-)
extern inline char load_env(void)	// v.1. >>> tag: exp->load_env
{
	return (_load_env((t_env_ *restrict const)&get_manager(NULL)->env));
}

// doc ...
__attribute__((hot, used))
//	(-public-)
extern inline char *gthome(void)	// v.1. >>> tag: exp->gthome
{
	return (_gethome((t_env_ *restrict const)&get_manager(NULL)->env));
}

// doc ...
__attribute__((hot, used))
//	(-public-)
extern inline char *gtpath(void)	// v.1. >>> tag: exp->gtpath
{
	return (_getpath((t_env_ *restrict const)&get_manager(NULL)->env));
}

// doc ...
__attribute__((hot, used))
//	(-public-)
extern inline char set(\
	const char *restrict const var
)	// v.1. >>> tag: exp->set
{
	return (_set((t_env_ *restrict const)&get_manager(NULL)->env, var));
}

// doc ...
__attribute__((hot, used))
//	(-public-)
extern inline char unset(\
	const char *restrict const var
)	// v.1. >>> tag: exp->unset
{
	return (_unset((t_env_ *restrict const)&get_manager(NULL)->env, var));
}


#endif
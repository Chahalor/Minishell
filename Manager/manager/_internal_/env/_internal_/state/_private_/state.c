/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/05/27 10:16:41 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STATE_C
# define STATE_C

/* -------- modules --------- */
	// ---- access ----- //
# include "state.h"

/* ------- functions -------- */

// doc ...
__attribute__((cold, used, malloc))
//	(-public-)
extern char	chuser(\
	const char *restrict const name
)	// v.1. >>> tag: exp->chuser
{
	return (_chuser((t_state_ *restrict const)&get_manager(NULL)->state, name));
}

// doc ...
__attribute__((hot, used, malloc))
//	(-public-)
extern char	chdir(\
	const char *restrict const dir
)	// v.1. >>> tag: exp->chdir
{
	return (_chdir((t_state_ *restrict const)&get_manager(NULL)->state, dir));
}

// doc ...
__attribute__((cold, used))
//	(-public-)
extern char	*gtuser(void)	// v.1. >>> tag: exp->gtuser
{
	return (_gtuser((const t_state_ *restrict const)&get_manager(NULL)->state));
}

// doc ...
__attribute__((hot, used))
//	(-public-)
extern char	*gtdir(void)	// v.1. >>> tag: exp->gtdir
{
	return (_gtdir((const t_state_ *restrict const)&get_manager(NULL)->state));
}

#endif
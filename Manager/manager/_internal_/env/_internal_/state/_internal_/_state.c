/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _state.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/05/27 10:16:07 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _STATE_C
# define _STATE_C

/* -------- modules --------- */
	// ---- access ----- //
# include "_state.h"

/* -------- inlines --------- */

// doc ...
__attribute__((always_inline, used))
//	(-hidden-)
extern inline char	_chuser(\
	t_state_ *restrict const state,
	const char *restrict const name
)	// v.1. >>> tag: def->chuser
{
	char		*restrict	_name;
	unsigned int			len;

	len = getlen(name, '\0');
	if (unexpect(alloc((void **)&_name, len + 1)))
		return (failed_to_allocate);
	free(state->user);
	copy(name, _name, len);
	state->user = _name;
	return (no_error);
}

// doc ...
__attribute__((always_inline, used))
//	(-hidden-)
extern inline char	_chdir(\
	t_state_ *restrict const state,
	const char *restrict const dir
)	// v.1. >>> tag: def->chdir
{
	char		*restrict	_dir;
	unsigned int			len;

	len = getlen(dir, '\0');
	if (unexpect(alloc((void **)&_dir, len + 1)))
		return (failed_to_allocate);
	free(state->dir);
	copy(dir, _dir, len);
	state->dir = _dir;
	return (no_error);
}

// doc ...
__attribute__((always_inline, used))
//	(-hidden-)
extern inline char	*_gtuser(\
	const t_state_ *restrict const state
)	// v.1. >>> tag: def->gtuser
{
	return (state->user);
}

// doc ...
__attribute__((always_inline, used))
//	(-hidden-)
extern inline char	*_gtdir(\
	const t_state_ *restrict const state
)	// v.1. >>> tag: def->gtdir
{
	return (state->dir);
}

#endif
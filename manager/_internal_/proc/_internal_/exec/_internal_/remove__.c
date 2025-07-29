/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init__.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/06/25 15:06:11 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REMOVE___C
# define REMOVE___C

/* -------- modules --------- */
	// ---- access ----- //
# include "exec__.h"

/* -------- inlines --------- */

// doc ...
__attribute__((always_inline, used))
// (-internal-)
extern inline char	__exec_close(\
	t_exec__ *restrict const exec__
	const int *restrict const pipe__,
	const int output__,
	int *restrict const last__
)	// v.1. >>> tag: def->_exec_close
{
	if (*last__ > 0)
		close(*last__);
	if (exec__->pipe__)
	{
		close(output__);
		*last__ = pipe__[0];
		return (exec__->pipe__);
	}
	return (NULL);
}

// doc ...
__attribute__((always_inline, used))
// (-internal-)
extern inline char	__exec_reset(\
	t_reader *restrict const reader__,
	t_server *restrict const server__
)	// v.1. >>> tag: def->_exec_reset
{
	fdm_close_all();	// @todo: replace by manager call
	reset_signal();		// function to set signal to default
}

#endif
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

#ifndef ADD___C
# define ADD___C

/* -------- modules --------- */
	// ---- access ----- //
# include "exec__.h"

/* -------- inlines --------- */

// doc ...
__attribute__((always_inline, used))
// (-internal-)
extern inline char	__exec_add_pipe(\
	t_reader *restrict const reader__,
	t_exec__ *restrict const exec__,
	int pipe__[2],
	int *output__
)	// v.1. >>> tag: def->_exec_add_pipe
{
	*output__ = 1 + (exec__->output__ > 0) * (exec__->output__ - 1);
	if (exec__->pipe__)
	{
		if (unexpect(pipe(pipe__) < 0))
			return (exec_pipe_failed_);
		else if (expect(output__))
			*output__ = pipe__[1];
		return (reader__->add(pipe__[0], NULL) \
				| reader__->add(pipe__[1], NULL));
	}
	if (exec__->output__ > -1)
	{
		close(*output__);
		*output__ = exec__->output__;
		pipe__[1] = *output__;
	}
	return (*output__);
}

// doc ...
__attribute__((always_inline, used))
// (-internal-) x (-local-)
extern inline char	__exec_redirect(\
	const int fd__,
	const int new__
)	// v.1. >>> tag: def->_exec_add_child
{
	if (unexpect((fd__ < 0 || new__ < 0) \
			|| (dup2(fd__, new__) != new__) \
			|| (close(fd__) != no_error)))
		return (error);
	return (no_error);
}

// doc ...
__attribute__((always_inline, used))
// (-internal-)
extern inline char	__exec_add_child(\
	t_env *restrict const env__,
	t_exec__ *restrict const exec__,
	const int last__,
	const int output__
)	// v.1. >>> tag: def->_exec_add_child
{
	if (exec__->input__ != 0 && exec__->input__ > 0)
		__exec_redirect(exec__->input__, 0);
	else if (last__ != 0 && last__ > 0)
		__exec_redirect(last__, 0);
	if (output__ != 1 && output__ > 0)
		__exec_redirect(output__, 1);
	_exec_child(exec__);
}

#endif
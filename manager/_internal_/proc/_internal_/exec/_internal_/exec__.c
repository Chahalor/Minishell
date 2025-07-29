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

#ifndef EXEC___C
# define EXEC___C

/* -------- modules --------- */
	// ---- access ----- //
# include "exec__.h"

/* -------- inlines --------- */

// doc ...
__attribute__((always_inline, used))
// (-internal-)
extern inline char	__exec_child(\
	t_env *restrict const env__,
	t_mem *restrict const mem__,
	t_exec__ *restrict const exec__,
)	// v.1. >>> tag: def->_exec_child
{
	if (unexpect(_exec_reset() != no_error || !exec__->cmd__))
		mem__->clean((unsigned char [1]){mem_all}, error, NULL, 0);
	execve(exec__->cmd__, exec__->args__, env__->vars());
	mem__->clean((unsigned char [1]){mem_all}, 127, NULL, 0);
	exit(error);
}

// doc ...
__attribute__((always_inline, used))
// (-internal-)
extern inline char	__exec_bin(\
	t_exec__ *restrict const exec__,
	const int last__,
	const int output__
)	// v.1. >>> tag: def->_exec_bin
{
	pid_t	pid__;

	pid__ = fork();
	if (pid__ == 0)
		_exec_add_child(exec__, last__, output__);
	else if (pid__ > 0)
	{
		exec__->pid__ = pid__;
		close(last__);
		return (no_error);
	}
	else
		return (error);
}

// doc ...
__attribute__((always_inline, used))
// (-internal-)
extern inline char	__exec_pipe(\
	t_exec__ *restrict const exec__
)	// v.1. >>> tag: def->_exec_pipe
{
	t_exec__	*current__;
	int			pipe__[2];
	int			output__;
	int			last__;

	last__ = -1;
	current__ = exec__;
	while (current__)
	{
		_exec_add_pipe(current__, pipe__, &output__);
		if (current__->builtin__)
			_exec_builtin_fork(current__, last__, output__);
		else
			_exec_bin(current__, last__, output__);
		current__ = _exec_close(current__, pipe__, output__, &last__);
	}
	return (_exec_wait(exec__));
}

// doc ...
__attribute__((always_inline, used))
// (-internal-)
extern inline char	__exec_cmd(\
	t_exec__ *restrict const exec__
)	// v.1. >>> tag: def->_exec_cmd
{
	int	input__;
	int	output__;

	input__ = -1;
	output__ = 1;
	output__ += (exec__->output__ > 0) * (exec__->out__ - 1);
	if (exec__->input__ > 0)
		input__ = exec__->input__;
	if (exec__->builtin__)
		_exec_builtin(exec__, input__, output__);
	else
		_exec_bin(exec__, input__, output__);
	return (_exec_wait(exec__));
}

// doc ...
__attribute__((always_inline, used))
// (-internal-)
extern inline char	__exec(\
	t_exec__ *restrict const exec__
)	// v.1. >>> tag: def->_exec
{
	if (exec__->pipe__)
		return (_exec_pipe(exec__));
	return (_exec_cmd(exec__));
}

#endif
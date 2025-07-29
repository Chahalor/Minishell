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

#ifndef WAIT___C
# define WAIT___C

/* -------- modules --------- */
	// ---- access ----- //
# include "exec__.h"

/* -------- inlines --------- */

// doc ...
__attribute__((always_inline, used))
// (-internal-)
extern inline char	__exec_signal(\
	t_visual *restrict const visual__
	const int status__
)	// v.1. >>> tag: def->_exec_signal
{
	if (WTERMSIG(status__) == SIGINT)
		return (130);
	else if (WTERMSIG(status__) == SIGQUIT)
	{
		visual__->fprintf(2, "Quit\n");
		return (131);
	}
	else if (WTERMSIG(status__) == SIGTERM)
	{
		visual__->fprintf(2, "Terminated\n");
		return (143);
	}
	else if (WTERMSIG(status__) == SIGKILL)
	{
		visual__->fprintf(2, "Killed\n");
		return (137);
	}
	else if (WCOREDUMP(status__))
	{
		visual__->fprintf(2, "Core dumped\n");
		return (128 + WTERMSIG(status__));
	}
	else
		return (128 + WTERMSIG(status__));
}

// doc ...
__attribute__((always_inline, used))
// (-internal-)
extern inline char	__exec_analyse(\
	t_visual *restrict const visual__
	const int status__
)	// v.1. >>> tag: def->_exec_analyse
{
	if (WIFEXITED(status__))
		return (WEXITSTATUS(status__));
	else if (WIFSIGNALED(status__))
		return (_exec_signal(status__));
	else if (WIFSTOPPED(status__))
	{
		visual__->fprintf(2, "Stopped\n");
		return (128 + WSTOPSIG(status__));
	}
	else
		return (-1);
}

// doc ...
__attribute__((always_inline, used))
// (-internal-)
extern inline char	__exec_wait(\
	t_exec__ *restrict const exec__
)	// v.1. >>> tag: def->_exec_wait
{
	int			status__;
	int			last__;

	status__ = 0;
	if (expect(exec__->pid__ > 0 && waitpid(exec__->pid__, &status__, 0)) != -1)
		exec__->status__ = _exec_analyse(status__);
	last__ = exec__->status__;
	if (expect(exec__->pipe))
		last__ = _exec_wait(exec__->pipe__);
	return (last__);
}

#endif
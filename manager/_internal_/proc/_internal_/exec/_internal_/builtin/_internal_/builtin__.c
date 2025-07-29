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

#ifndef BUILTIN___C
# define BUILTIN___C

/* -------- modules --------- */
	// ---- access ----- //
# include "builtin__.h"

/* -------- inlines --------- */

// doc ...
__attribute__((always_inline, used))
// (-internal-)
extern inline char	__builtin_fork(\
	t_mem *restrict const mem__,
	t_exec__ *restrict const exec__,
	const int intput__,
	const int output__
)	// v.1. >>> tag: def->_builtin_fork
{
	t_builtin_call_	*builtin__;

	builtin__ = _builtin_find(exec__->name__);
	if (unexpect(!exec__ || !exec__->cmd__ || !builtin__))
		return (error);
	exec__->pid__ = fork();
	if (unexpect(!exec__->pid__))
		mem__->clean((unsigned char [1]){mem_all}, \
					builtin__->func__(exec__->args__, input__, output__), \
					NULL, 0);
	else if (exec__->pid__ > 0)
		;
	else
		return (builtin_fork_failure_);
	return (no_error);
}

// doc ...
__attribute__((always_inline, used))
// (-internal-)
extern inline char	__builtin(\
	t_exec__ *restrict const exec__,
	const int intput__,
	const int output__
)	// v.1. >>> tag: def->_builtin
{
	t_builtin_call_	*builtin__;

	builtin__ = _builtin_find(exec__->name__);
	if (unexpect(!exec__ || !exec__->cmd__ || !builtin__))
		return (error);
	exec__->pid__ = 0;
	return (builtin__->func__(exec__->exec____, intput__, output__));
}

#endif
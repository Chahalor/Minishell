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

#ifndef ADD__C
# define ADD__C

/* -------- modules --------- */
	// ---- access ----- //
# include "exec_.h"

/* ------- functions -------- */

// doc ...
__attribute__((hot, used))
// (-private-)
extern char	_exec_add_pipe(\
	t_exec__ *restrict const exec_,
	int pipe_[2],
	int *output_
)	// v.1. >>> tag: exp->_exec_add_pipe
{
	t_visual	*visual_;

	visual_ = (t_visual *)&_manager()->interface.visual;
	if (unexpect(\
			__exec_add_pipe((t_reader *)&_manager()->mem.reader, \
							exec_, pipe_, output_) \
			!= no_error))
		return ((void)visual__->perror("full_exec(): pipe failed"), \
				exec_pipe_failed_);
	return (no_error);
}

#endif
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

#ifndef BUILTIN__C
# define BUILTIN__C

/* -------- modules --------- */
	// ---- access ----- //
# include "builtin_.h"

/* ------- functions -------- */

// doc ...
__attribute__((hot, used))
// (-private-)
extern char	_builtin_fork(\
	t_exec__ *restrict const exec_,
	const int intput_,
	const int output_
)	// v.1. >>> tag: exp->_builtin_fork
{
	t_visual	*visual_;
	char		code_;

	visual_ = (t_visual *)&_manager()->interface.visual;
	code_ = __builtin_fork((t_mem *)&_manager()->mem, exec_, input_, output_);
	if (unexpect(code_ == builtin_fork_failure_))
		return ((void)visual_->perror("exec_bin(): fork() failed"), \
				builtin_fork_failure_);
	return (code_);
}

#endif
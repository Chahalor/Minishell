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

#ifndef EXEC__C
# define EXEC__C

/* -------- modules --------- */
	// ---- access ----- //
# include "exec_.h"

/* ------- functions -------- */

// doc ...
__attribute__((hot, used))
// (-private-)
extern inline char	_exec_bin(\
	t_exec__ *restrict const exec_,
	const int last_,
	const int output_
)	// v.1. >>> tag: exp->_exec_bin
{
	t_visual	*visual_;

	visual_ = (t_visual *)&_manager()->interface.visual;
	if (unexpect(__exec_bin(exec_, last_, output_) != no_error))
		return (visual_->perror("exec_bin__(): fork() failed"), error);
	return (no_error);
}

#endif
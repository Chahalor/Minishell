/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _history.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/05/23 10:59:17 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNLOAD__C
# define UNLOAD__C

/* -------- modules --------- */
	// ---- access ----- //
# include "history_.h"

/* ------- functions -------- */

// doc ...
__attribute__((cold, used))
//	(-private-)
extern char	_histo_show(void)	// v.1. >>> tag: exp->_histo_show
{
	return (__histo_show((t_histo *)&_histo_self()->_internal_, \
						(t_visual *)&_manager()->interface.visual));
}

#endif
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

#ifndef INIT___C
# define INIT___C

/* -------- modules --------- */
	// ---- access ----- //
# include "visual__.h"

/* -------- inlines --------- */

// doc ...
__attribute__((always_inline, used))
// (-internal-)
extern inline char	__visual_init(\
	t_visual_ *restrict const visual__
)	// v.1. >>> tag: def->visual_init
{
	*visual__ = (t_visual_){\
		.printf_ = _visual_printf, \
		.rprintf_ = _visual_rprintf, \
		.fprintf_ = _visual_fprintf, \
		.sprintf_ = _visual_sprintf, \
		.perror_ = _visual_perror \
	};
	if (unexpect(!_visual_get(visual__)))
		return (failed_to_setup);
	return (no_error);
}

#endif
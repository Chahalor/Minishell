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

#ifndef INIT_C
# define INIT_C

/* -------- modules --------- */
	// ---- access ----- //
# include "visual.h"

/* -------- inlines --------- */

// doc ...
__attribute__((always_inline, used))
// (-public-)
extern inline char	visual_init(\
	t_visual *restrict const visual
)	// v.1. >>> tag: exp->visual_init
{
	return (__visual_init((t_visual_ *)visual));
}

#endif
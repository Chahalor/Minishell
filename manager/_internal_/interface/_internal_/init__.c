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
# include "interface__.h"

/* -------- inlines --------- */

// doc ...
__attribute__((always_inline, used))
// (-internal-)
extern inline char	__interface_init(\
	t_interface_ *restrict const interface__
)	// v.1. >>> tag: def->interface_init
{
	*interface__ = (t_interface_){\
		// ...
	};
	if (unexpect(!_interface_get(interface__)))
		return (failed_to_setup);
	return (no_error | server_init(&interface__->server_) \
			| no_error | visual_init(&interface__->visual_)); // placeholder for modules.
}

#endif
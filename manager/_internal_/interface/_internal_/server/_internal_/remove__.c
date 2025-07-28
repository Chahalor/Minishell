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

#ifndef REMOVE___C
# define REMOVE___C

/* -------- modules --------- */
	// ---- access ----- //
# include "server__.h"

/* -------- inlines --------- */

// doc ...
__attribute__((always_inline, used))
// (-internal-)
extern inline char	__server_reset(void)	// v.1. >>> tag: def->_server_reset
{
	return (signal(SIGINT, SIG_DFL) \
			| signal(SIGQUIT, SIG_DFL) \
			| signal(SIGTSTP, SIG_DFL));
}

#endif
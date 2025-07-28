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

#ifndef ADD___C
# define ADD___C

/* -------- modules --------- */
	// ---- access ----- //
# include "server__.h"

/* -------- inlines --------- */

// doc ...
__attribute__((always_inline, used))
// (-internal-)
extern inline char	__server_add(\
	t_signal_ *restrict const signal__,
	const void *restrict const handler__
)	// v.1. >>> tag: def->_server_init
{
	signal__->sa_sigaction = handler__;
	signal__->sa_flags = SA_SIGINFO | SA_RESTART;
	sigemptyset(&server__->sa_mask);
	return (sigaction(SIGINT, &signal__, NULL))
}

#endif
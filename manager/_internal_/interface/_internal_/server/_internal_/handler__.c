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

#ifndef HANDLER___C
# define HANDLER___C

/* -------- modules --------- */
	// ---- access ----- //
# include "server__.h"

/* -------- inlines --------- */

// doc ...
__attribute__((always_inline, used))
// (-internal-)
extern inline char	__server_sigint_handler(\
	const int signal__
)	// v.1. >>> tag: def->_server_sigint_handler
{
	g_signal = signal__;
}

// doc ...
__attribute__((always_inline, used))
// (-internal-)
extern inline char	__server_sigquit_handler(\
	const int signal__
)	// v.1. >>> tag: def->_server_sigquit_handler
{
	g_signal = signal__;
}

// doc ...
__attribute__((always_inline, used))
// (-internal-)
extern inline char	__server_sigstop_handler(\
	const int signal__
)	// v.1. >>> tag: def->_server_sigstop_handler
{
	g_signal = signal__;
}

#endif
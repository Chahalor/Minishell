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

#ifndef HANDLER__C
# define HANDLER__C

/* -------- modules --------- */
	// ---- access ----- //
# include "server_.h"

/* ------- functions -------- */

// doc ...
__attribute__((hot, used))
// (-private-)
extern char	_server_sigint_handler(\
	int signal_,
	t_infos_ *infos_,
	void *context_
)	// v.1. >>> tag: exp->_server_sigint_handler
{
	return ((void)infos_, (void)context_, __server_sigint_handler(signal_));
}

// doc ...
__attribute__((cold, used))
// (-private-)
extern char	__server_sigquit_handler(\
	int signal_,
	t_infos_ *infos_,
	void *context_
)	// v.1. >>> tag: exp->_server_sigquit_handler
{
	return ((void)infos_, (void)context_, __server_sigquit_handler(signal_));
}

// doc ...
__attribute__((cold, used))
// (-private-)
extern char	__server_sigstop_handler(\
	int signal_,
	t_infos_ *infos_,
	void *context_
)	// v.1. >>> tag: exp->_server_sigstop_handler
{
	return ((void)infos_, (void)context_, __server_sigstop_handler(signal_));
}

#endif
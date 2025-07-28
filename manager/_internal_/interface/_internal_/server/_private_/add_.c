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

#ifndef ADD__C
# define ADD__C

/* -------- modules --------- */
	// ---- access ----- //
# include "server_.h"

/* -------- inlines --------- */

// doc ...
__attribute__((always_inline, used))
// (-private-)
extern inline char	_server_add(\
	t_signal_ *restrict const signal_,
	const void *restrict const handler_
)	// v.1. >>> tag: exp->_server_init
{
	return (__server_add(signal_, handler_));
}

#endif
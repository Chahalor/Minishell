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

#ifndef REMOVE__C
# define REMOVE__C

/* -------- modules --------- */
	// ---- access ----- //
# include "server_.h"

/* ------- functions -------- */

// doc ...
__attribute__((cold, used))
// (-private-)
extern inline char	_server_reset(void)	// v.1. >>> tag: exp->_server_reset
{
	return (__server_reset());
}

#endif
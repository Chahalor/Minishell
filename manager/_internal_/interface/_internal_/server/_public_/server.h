/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _manager.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/05/23 15:17:06 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# pragma once

/* -------- modules --------- */
	// --- internal ---- //
# include "../_internal_/server__.h"

	// ---- locals ----- //
# include "./types.h"

/* ------- prototypes ------- */
	// ---- public ----- //
// init :
extern char		server_init(\
					t_server *restrict const server
					)
				__attribute__((\
					always_inline, used, \
					visibility("default")));

#endif
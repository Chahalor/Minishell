/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/05/20 16:21:15 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MANAGER_H
# define MANAGER_H

# pragma once

/* -------- modules --------- */
	// --- internals --- //
# include "_internal_/_manager.h"

	// ---- locals ----- //
# include "./types.h"

/* ------- prototypes ------- */
	// ---- exposed ---- //
// setup :
extern t_manager		*setup_manager(\
							char *restrict *restrict const env
							)
						__attribute__((\
							cold, used, \
							malloc, visibility("default")));
// access :
extern t_manager		*get_manager(\
							t_manager	*restrict const new
							)
						__attribute__((\
							hot, used, \
							visibility("default")));

// state :
extern char				chuser(\
							const char *restrict const name
							)
						__attribute__((\
							cold, used, \
							malloc, visibility("default")));
extern char				chdir(\
							const char *restrict const dir
							)
						__attribute__((\
							hot, used, \
							malloc, visibility("default")));
extern char				chpath(\
							const char *restrict const path
							)
						__attribute__((\
							cold, used, \
							malloc, visibility("default")));

#endif
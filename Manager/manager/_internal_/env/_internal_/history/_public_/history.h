/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/05/23 13:59:45 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HISTORY_H
# define HISTORY_H

# pragma once

/* -------- modules --------- */
	// --- internals --- //
# include "_internal_/_history.h"

	// ---- locals ----- //
# include "./types.h"

/* ------- prototypes ------- */
	// ---- hidden ----- //
// methods :
extern char				load_history(void)
						__attribute__((\
							cold, used, \
							visibility("hidden")));
extern void				unload_history(void)
						__attribute__((\
							cold, used, \
							visibility("hidden")));
extern char				show_history(void)
						__attribute__((\
							cold, used, \
							visibility("hidden")));
extern char				add_entry(\
							const char *restrict const command
							)
						__attribute__((\
							hot, used, \
							visibility("hidden")));
extern char 			*get_entry(\
							const unsigned int index
							)
						__attribute__((\
							hot, used, \
							visibility("hidden")));

	// ---- exposed ---- //
// init :
extern char				init_history(\
							t_histo *restrict history
							)
						__attribute__((\
							cold, used, \
							visibility("default")));

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/06/19 13:39:48 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READER_H
# define READER_H

# pragma once

/* -------- modules --------- */
	// --- internals --- //
# include "_internal_/_reader.h"

/* ------- prototypes ------- */
	// ---- exposed ---- //
// open :
extern char		open(\
					const char *restrict const path,
					unsigned int *restrict fd
					)
				__attribute__((\
					cold, used, \
					visibility("default")));
// read :
extern char		read(\
					unsigned int *restrict fd,
					char *restrict const buffer
					)
				__attribute__((\
					hot, used, \
					visibility("default")));
// write :
extern char		write(\
					const unsigned int fd,
					const char *restrict const buffer,
					const unsigned int size
					)
				__attribute__((\
					hot, used, \
					visibility("default")));

#endif
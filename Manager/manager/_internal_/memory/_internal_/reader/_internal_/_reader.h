/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _reader.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/06/19 14:14:33 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _READER_H
# define _READER_H

# pragma once

/* -------- modules --------- */
	// ---- locals ----- //
# include "./_types.h"

	// ---- globals ---- //
# include "memory/memory.h"
# include "utils/utils.h"

/* ------- prototypes ------- */
	// ---- hidden ----- //
// open :
extern char		_open(\
					const char *restrict const path,
					unsigned int *restrict fd
					)
				__attribute__((\
					always_inline, used, \
					visibility("hidden")));
// read :
extern char		_read(\
					unsigned int *restrict fd,
					char *restrict const buffer
					)
				__attribute__((\
					always_inline, used, \
					visibility("hidden")));
// write :
extern char		_write(\
					const unsigned int fd,
					const char *restrict const buffer,
					const unsigned int size
					)
				__attribute__((\
					always_inline, used, \
					visibility("hidden")));

#endif
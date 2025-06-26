/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _write.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/05/22 13:45:35 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _WRITE_C
# define _WRITE_C

/* -------- modules --------- */
	// ---- access ----- //
# include "_reader.h"

/* -------- inlines --------- */

// doc ...
__attribute__((always_inline, used))
// (-hidden-)
extern inline char	_write(\
	const unsigned int fd,
	const char *restrict const buffer,
	const unsigned int size
)	// v.1. >>> tag: def->write
{
	if (unexpect(write(fd, buffer, size) < size))
		return (failed_to_write);
	return (no_error);
}

#endif